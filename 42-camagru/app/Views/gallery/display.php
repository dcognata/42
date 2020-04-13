<div class="col-8 col-m-12">
  <h1>Galerie</h1>
  <div class="row" id="content-loader">
    <?php foreach ($lastPictures as $key => $picture) { ?>
    <div class="col-6 col-m-12">
      <div class="card" id="<?= $picture->id ?>">
        <a href="index.php?p=gallery.view&id=<?= $picture->id ?>">
            <img class="img-fluid" src="<?= $app->getAsset($picture->path) ?>">
        </a>
        <div class="info-img">
          <span class="pull-left">
            <i class="fa fa-heart" aria-hidden="true"><?= $picture->likes ?></i>
          </span>
          <span class="pull-right">
            <?= $picture->comments ?> <i class="fa fa-comment" aria-hidden="true"></i>
          </span>
        </div>
      </div>
    </div>
    <?php } ?>
  </div>
</div>

<script type="text/javascript">
var nbDisplay = 0;
function _create_div(data) {
	data.forEach(function(item){
	    html = $('<div class="col-6 col-m-12">').append($("<div class='card' id='"+item.id+"'><a href='index.php?p=gallery.view&id="+item.id+"'><img class='img-fluid' src='public"+item.path+"'></a><div class='info-img'><span class='pull-left'><i class='fa fa-heart' aria-hidden='true'>"+item.likes+"</i></span><span class='pull-right'> "+item.comments+" <i class='fa fa-comment' aria-hidden='true'></i></span></div></div>"));
		$('#content-loader').append(html);
	});
}
function _ajax_get_data() {
    $.ajax({
       url : 'index.php?p=gallery.ajaxInfinityLoader',
       type : 'POST',
       data : {'nbDisplay': nbDisplay },
       dataType: "json",
       success : function(data, statut){
       		console.log("Load 6 news pics");
       		_create_div(data);
       },
       error : function(resultat, statut, erreur){
       		console.log('Error');
       },
    });
}
$(window).scroll(function() {
    if($(window).scrollTop() == $(document).height() - $(window).height()) {
        nbDisplay++;
        setTimeout(_ajax_get_data, 500);
    }
});
</script>

<script type="text/javascript">
  $(document).on('click', '.fa-heart', function() {
    var clicked = $(this);
    $.ajax({
      url : 'index.php?p=gallery.likeAjax',
      type : 'POST',
      data : {'id': $(this).parent().parent().parent().attr('id') },
      dataType: "json",
      success : function(data, statut){
        console.log(data);
        if (data == 'unlike') {
          clicked.css('color', 'white');
          clicked.html(parseInt(clicked.html(), 10)-1)
        } else if (data == 'like') {
          clicked.css('color', 'red');
          clicked.html(parseInt(clicked.html(), 10)+1)
        }
      },
      error : function(resultat, statut, erreur){
        console.log('Error: ' + resultat + erreur);
      },
    });
  });
</script>