<?php
/**
 * This .inc file contains most of the logic for the browse virtual stores feature.
 */

function virtual_shelf($tid) {

  // sanitize and verify that we have a valid term id
  check_plain($tid);
  $termObj = taxonomy_term_load($tid);

  //dpm($termObj);

  if ($termObj->tid !== $tid) {
    dpm('Invalid term ID.');
    return 'The value provided is not a valid term ID.';
  }

  else {

    // load the flexslider javascript that will be used for the shelf views

    drupal_add_js('sites/all/libraries/flexslider/jquery.flexslider.js');
    drupal_add_js('sites/all/libraries/jquery.mousewheel/jquery.mousewheel.min.js');
    drupal_add_js('sites/all/modules/gpii_saa_custom/js/browse-shelf.js');


    // add flexslider CSS
    drupal_add_css('sites/all/libraries/flexslider/flexslider.css');


    // Generate the markup from a view
    // Note that tooltip text will need to be duplicated in a .sr-only
    // Demo Page http://dev.saa.gpii.net/search/virtual/shelf/3993

    $markup .= <<<END
    <div class="container" id="flexslider-wrap">
      <div class="row">
        <div class="col-md-1 flex-preface"><p class="sr-only">Start Shelf</p></div>
        <div class="flexslider col-md-22">
          <ul class="slides">
            <li class="first">
              <div>
              <h3>Example Title</h3>
              <p class="text-center"><img src="/sites/saa.gpii.net/files/uploads/products/images/node/230/victorreaderstream.jpg" alt="Image 1" /></p>
              </div>
            </li>
            <li>
              <div>
                <h3><a href="http://google.com">Smart Beetle</a></h3>
                <p class="text-center"><img src="/sites/saa.gpii.net/files/uploads/products/images/node/3572/smart-beetle.jpg"  alt="Image 2" /></p>
                <button type="button" class="btn btn-secondary" data-toggle="tooltip" data-html="true" title="<em>Tooltip</em> <u>with</u> <b>HTML</b>. A short description of the product goes here and is no more than a sentence or two. The reason is that we have to pick a sensible height to cap these things at so that products can "sit" on the shelf. ">
  (i)
</button>

              </div>
            </li>
            <li>
              <div>
                <h3>ElBraille Notetaker</h3>
                <p class="text-center"><img src="/sites/saa.gpii.net/files/uploads/products/images/node/3664/elbraillenotetaker.jpg" alt="Image 3" /></p>
              </div>
            </li>
            <li>
              <div>
                <h3>VIEWPLUS TECHNOLOGIES - IVEO TOUCHPAD COMPLETO</h3>
                <p class="text-center"><img src="/sites/saa.gpii.net/files/uploads/products/images/node/1384/i4.png" alt="Image 4" /></p>
              </div>
            </li>
            <!-- items mirrored twice, total of 12 -->
            <li>
              <div><img src="/sites/saa.gpii.net/files/uploads/products/images/node/230/victorreaderstream.jpg" alt="Image 5" /></div>
            </li>
            <li>
              <div><img src="/sites/saa.gpii.net/files/uploads/products/images/node/3572/smart-beetle.jpg" alt="Image 6" /></div>
            </li>
            <li>
              <div><img src="/sites/saa.gpii.net/files/uploads/products/images/node/3664/elbraillenotetaker.jpg" alt="Image 7" /></div>
            </li>
            <li>
              <div>
              <h3><a href="http://google.com">Smart Beetle</a></h3>
              <p><img src="/sites/saa.gpii.net/files/uploads/products/images/node/1384/i4.png" alt="Image 8" /></p></div>
            </li>
            <li>
              <div><img src="/sites/saa.gpii.net/files/uploads/products/images/node/230/victorreaderstream.jpg" alt="Image 9" /></div>
            </li>
            <li>
              <div><img src="/sites/saa.gpii.net/files/uploads/products/images/node/3572/smart-beetle.jpg" alt="Image 10" /></div>
            </li>
            <li>
              <div><img src="/sites/saa.gpii.net/files/uploads/products/images/node/3664/elbraillenotetaker.jpg" alt="Image 11" /></div>
            </li>
            <li class="last">
              <div class="image-container"><img src"" data-src="/sites/saa.gpii.net/files/styles/magnific_popup_thumbnail/public/uploads/products/images/node/3453/proslate.gif" alt="Test Image" /></div>
            </li>
          </ul>
        </div>
        <div class="col-md-1 flex-suffix"><p class="sr-only">End Shelf</p></div>
      </div>
    </div>

END;

    return '<strong>Shelf Label: </strong>' . $termObj->name . '<br />' . $markup;

  }




}

 ?>
