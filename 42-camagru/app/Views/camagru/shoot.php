<div class="col-6 col-m-12">
    <h1>Studio</h1>
    <div class="bloc-picture">
    <!-- <div > -->
        <video class="video" id="video" autoplay="true"
        muted="muted"></video>
        <div id="background"></div>
        <canvas id="canvas"></canvas>
    <!-- </div> -->
    </div>
    <div class="clearfix"></div>
    <div class="field is-grouped">
        <div class="control">
            <br>
            <input type="file" id="picture_input" name="picture_input" accept="image/*">
            <p class="error"></p>
            <button class="button is-primary" id="startbutton" disabled>Prendre une photo</button>
            <button class="button is-primary" id="uploadbutton" disabled>Uploader une image</button>
        </div>
    </div>
</div>

<div class="col-3 col-m-12">
  <div class="aside" id="firstB">
    <h2>Fonctionnement</h2>
    <p>Sélectionnez un calque et prenez la photo.</p>
    <p>Les photos seront publiés dans la galerie.</p>
      <input type="radio" onclick="changeId(1)" name="gender" value="male"> <img src="<?= $app->getAsset('images/1.png'); ?>" height="80px" width="100px"><br>
      <input type="radio"  onclick="changeId(2)" name="gender" value="male"> <img src="<?= $app->getAsset('images/2.png'); ?>" height="80px" width="100px"><br>
      <input type="radio"  onclick="changeId(3)" name="gender" value="male"> <img src="<?= $app->getAsset('images/3.png'); ?>" height="80px" width="100px"><br>
      <input type="radio"  onclick="changeId(4)" name="gender" value="male"> <img src="<?= $app->getAsset('images/4.png'); ?>" height="80px" width="100px"><br>
      <input type="radio" name="gender" onclick="changeId(null)" value="other"> Sans image
  </div>
  <div class="aside">
    <h2>Vos photos</h2>
    <div id="photo">
    <?php
        if ($auth->logged()) {
            foreach ($myPictures as $key => $value) {
    ?>
        <p>
            <img src="<?= $app->getAsset($value->path); ?>" class="img-fluid">
        </p>
    <?php
            }
        }
    ?>
    </div>
  </div>
</div>

<script>
var on = true;
var img_id = null;
var up_img = null;

function resize(){
  $("#canvas").outerHeight(document.querySelector('.bloc-picture').offsetHeight);
  $("#canvas").outerWidth(document.querySelector('.bloc-picture').offsetWidth);
}

$(document).ready(function(){
  resize();
  $(window).on("resize", function(){                      
      resize();
  });
});

function changeBackGround(input) {
  if (input.files && input.files[0]) {
    var reader = new FileReader();
    if (input.files[0].type == 'image/jpeg' || input.files[0].type == 'image/png' || input.files[0].type == 'image/gif') {
      reader.onload = function(e) {
        up_img = e.target.result;
      };
      reader.readAsDataURL(input.files[0]);
      $('.error').html('');
    } else {
      up_img = null;
      $('.error').html('Le type '+ input.files[0].type +' n\'est pas valide.');
      document.getElementById("uploadbutton").disabled = true;
    }
  }
}

$("#picture_input").change(function() {
  changeBackGround(this);
  if (img_id != null)
    document.getElementById("uploadbutton").disabled = false;
});
$("#uploadbutton").click(function() {
  console.log('upload........');
  if ($('#picture_input').val() != "") {
    $('.error').html('');
    ajaxRequest("index.php?p=camagru.shootSave", up_img);
  } else {
    $('.error').html('Merci d\'ajouter une image');
  }
});

document.addEventListener("DOMContentLoaded", function(event) {
  var streaming = false,
      video = document.querySelector('#video'),
      canvas = document.querySelector('#canvas'),
      startbutton = document.querySelector('#startbutton'),
      width = document.querySelector('.bloc-picture').offsetWidth,
      height = document.querySelector('.bloc-picture').offsetHeight;

  navigator.getMedia = ( navigator.getUserMedia ||  navigator.webkitGetUserMedia || navigator.mozGetUserMedia || navigator.msGetUserMedia );

  navigator.getMedia(
    { 
      video: true, 
      audio: false 
    },
    function(stream) {
      if (navigator.mozGetUserMedia) { 
        video.mozSrcObject = stream;
      } else {
        video.srcObject=stream;
        video.play();

      }
      video.play();
    },
    function(err) {
      console.log("An error occured! " + err);
      on = false;
    }
  );

  video.addEventListener('canplay', function(ev){
    if (!streaming) {
      height = video.videoHeight / (video.videoWidth/width);
      video.setAttribute('width', width);
      video.setAttribute('height', height);
      canvas.setAttribute('width', width);
      canvas.setAttribute('height', height);
      streaming = true;
    }
  }, false);

  function takepicture() {
    canvas.width = width;
    canvas.height = height;
    var ctx = canvas.getContext('2d');
    ctx.drawImage(video, 0, 0, width, height);
    var data = canvas.toDataURL('image/png');
    return data;
  }

  startbutton.addEventListener('click', function(ev){
    if (on == true) {
      var data = takepicture();
      if (data) {
        ajaxRequest("index.php?p=camagru.shootSave", data);
        console.log('Photo prise');
      }
    }
    ev.preventDefault();
  }, false);

});

function create_img(url)
{
  var photo = document.querySelector('#photo');
  var elem = document.createElement("p");
  elem.innerHTML = "<a href=\"index.php?p=camagru.delete&path="+url+"\"><img src=" + url + " class=\"img-fluid\" crossOrigin=\"Anonymous\" onmouseout=\"this.src='" + url +"';\" onmouseover=\"this.src='public/images/delete.png';\"/></a>";
  photo.prepend(elem);
}

function ajaxRequest(url, data){
  var xmlhttp;
  var params = "img="+data+"&id="+img_id;
  if (window.XMLHttpRequest) {
    xmlhttp=  new XMLHttpRequest();
  } else {
    xmlhttp= new ActiveXObject("Microsoft.XMLHTTP");
  }
  xmlhttp.onreadystatechange=function() {
    if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
      create_img(xmlhttp.responseText);
    }
  }
  xmlhttp.open("POST", url, true);
  xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
  xmlhttp.send(params);
}

function changeId(id)
{
  bck = document.querySelector('#background');
  if (id != null)
  {
    if (on == true) {
      bck.style.backgroundImage = "url('public/images/" + id + ".png')";
      document.getElementById("startbutton").disabled = false;
    }
    if ($('#picture_input').val() != "")
       document.getElementById("uploadbutton").disabled = false;
    document.getElementById("picture_input").disabled = false;
    img_id = id;
  }
  else
  {
    if (on == true)
        bck.style.backgroundImage = "none";
    document.getElementById("startbutton").disabled = true;
    document.getElementById("uploadbutton").disabled = true;
    document.getElementById("picture_input").disabled = true;
    img_id = null;
  }
}
</script>