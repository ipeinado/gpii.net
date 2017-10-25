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
    // View Source Ref http://dev.saa.gpii.net/admin/browse/shelf/3698
    //
    // Demo: http://dev.saa.gpii.net/search/virtual/shelf/3698


    $results = views_get_view_result('browse_shelf', 'page_1', $tid);

    //dpm($results);

    $resultCount = count($results);


    if ($resultCount > 0) {
      $markup .= <<<END
      <div class="container" id="flexslider-wrap">
        <div class="row">
          <div class="col-md-1 flex-preface"><p class="sr-only">Start Shelf</p></div>
          <div class="flexslider col-md-22">
            <ul class="slides">

END;

      foreach ($results as $key => $value) {
        if ($key === 0) {
          $markup .= '<li class="first">';
        }
        elseif ($key ===  ($resultCount - 1)) {
          $markup .= '<li class="last">';
        }
        else {
          $markup .= '<li>';
        }
        // consider target="_blank" so that users don't lose their place on the shelf. Other option is to add a modal

        $markup .= '<div><h3><a href="/node/' . $value->nid . '">' . $value->node_title . '</a></h3>';

// @@ Add missing alt text

        $markup .= '<p class="text-center">' . theme('image_style',array('style_name' => 'medium', 'path' => $value->field_field_product_image[0]['rendered']['#item']['uri'])) . '</p></div>';

        $markup .= '<div class="description"><p>' . strip_tags($value->field_body[0]['rendered']['#markup']) . '</p></div>';

        $markup .= '</li>';
      }

      $markup .= <<<END
            </ul>
          </div>
          <div class="col-md-1 flex-suffix"><p class="sr-only">End Shelf</p></div>
        </div>
      </div>

END;

// @@ consider lazy loading some of these (code example follows)
// <div class="image-container"><img src"" data-src="/sites/saa.gpii.net/files/styles/magnific_popup_thumbnail/public/uploads/products/images/node/3453/proslate.gif" alt="Test Image" /></div>

    }

    drupal_set_title($title = $termObj->name, $output = CHECK_PLAIN);

    return $markup;

  }




}

 ?>
