<div class="col-6 col-m-12">
  <div class="row" id="content-view">
    <div class="col-12">
        <center>
            <div>
                <!-- Facebook -->
                <a target="_blank" title="Facebook" href="https://www.facebook.com/sharer.php?u=<?= 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']; ?>" rel="nofollow" onclick="javascript:window.open(this.href, '', 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes,height=500,width=700');return false;"><img src="<?= $app->getAsset('images/facebook.png') ?>" alt="Facebook" width="24px"/></a>
                <!-- //Facebook -->

                <!-- Twitter -->
                <a target="_blank" title="Twitter" href="https://twitter.com/share?url=<?= 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']; ?>" rel="nofollow" onclick="javascript:window.open(this.href, '', 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes,height=400,width=700');return false;"><img src="<?= $app->getAsset('images/twitter.png') ?>" alt="Twitter" width="24px"/></a>
                <!-- //Twitter -->

                <!-- Google + -->
                <a target="_blank" title="Google +" href="https://plus.google.com/share?url=<?= 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']; ?>" rel="nofollow" onclick="javascript:window.open(this.href, '', 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes,height=450,width=650');return false;"><img src="<?= $app->getAsset('images/google.png') ?>" alt="Google Plus" width="24px"/></a>
                <!-- //Google + -->

                <!-- Linkedin -->
                <a target="_blank" title="Linkedin" href="https://www.linkedin.com/shareArticle?mini=true&amp;url=<?= 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']; ?>" rel="nofollow" onclick="javascript:window.open(this.href, '','menubar=no,toolbar=no,resizable=yes,scrollbars=yes,height=450,width=650');return false;"><img src="<?= $app->getAsset('images/linkedin.png') ?>" alt="Linkedin" width="24px"/></a>
                <!-- //Linkedin -->

                <!-- Email -->
                <a target="_blank" title="Envoyer par mail" href="mailto:?Subject=Regarde ça c'est cool ! <?= 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']; ?>" rel="nofollow"><img src="<?= $app->getAsset('images/mail.png') ?>" alt="email" width="24px"/></a>
                <!-- //Email -->
            </div>
        </center>
      <div class="card" id="<?= $pic->id ?>">
        <img class="img-fluid" src="<?= $app->getAsset($pic->path) ?>">
        <div class="info-img">
          <span class="pull-left">
            <i class="fa fa-heart" style="<?php if ($like) { ?>color:red<?php } ?>" aria-hidden="true"><?= $pic->likes ?></i>
          </span>
          <span class="pull-right">
            <i class="fa fa-comment" aria-hidden="true"><?= $pic->comments ?></i>
          </span>
        </div>
      </div>
      <?php if ($pic->user_id == $auth->getUserId()) { ?>
        <a href="/index.php?p=gallery.delete&id=<?= $pic->id ?>" class="button pull-right">Supprimer</a>
      <?php } ?>
    </div>
  </div>
</div>
<div class="col-3 col-m-12">
    <div class="row">
        <?php foreach ($comments as $key => $comment) { ?>
        <div class="col-12">
            <div class="comment">
                <h2><?= $comment->username ?></h2>
                <p><?= $comment->comment ?></p>
                <p class="date">
                    Le <?= \DateTime::createFromFormat('Y-m-d H:i:s', $comment->publishedAt)->format('d/m/Y H:i') ?>
                    <i class="fa fa-clock-o" aria-hidden="true"></i>
                    <?php if ($comment->user_id == $auth->getUserId()) { ?>
                        <a href="/index.php?p=comment.delete&id=<?= $comment->c_id ?>"><i class="fa fa-trash" aria-hidden="true"></i></a>
                    <?php } ?>
                </p>
            </div>
        </div>
        <?php } ?>
        <div class="col-12">
            <?php if ($auth->logged()) { ?>
            <form method="post">
                <?= $form->input('comment', 'Commentaire',
                    array(
                        'icon' => 'fa fa-comment',
                        'maxlength' => 300,
                        'required' => true,
                    ),
                    $errorComment
                ) ?>
                <?= $form->token($errorToken) ?>
                <button class="button xs is-primary" name="submit" value="true">POSTER</button>
            </form>
            <?php } ?>
        </div>
    </div>
</div>

<script type="text/javascript">
$('.fa-heart').click(function (){
  $.ajax({
    url : 'index.php?p=gallery.likeAjax',
    type : 'POST',
    data : {'id': $('.card').attr('id') },
    dataType: "json",
    success : function(data, statut){
      console.log(data);
      if (data == 'unlike') {
        $('.fa-heart').css('color', 'white');
        $('.fa-heart').html(parseInt($('.fa-heart').html(), 10)-1)
      } else if (data == 'like') {
        $('.fa-heart').css('color', 'red');
        $('.fa-heart').html(parseInt($('.fa-heart').html(), 10)+1)
      }
    },
    error : function(resultat, statut, erreur){
      console.log('Error: ' + resultat + erreur);
    },
  });
});
</script>