<?php
/**
 * This .inc file contains most of the logic for the browse virtual stores feature.
 */


function virtual_stores() {

  // grab a view that pulls in all the stores and icons we need to build the page
  $results = views_get_view_result('virtual_stores', 'default', NULL);
  //dpm($results);

  $markup .= '<div class="browse-store-wrapper">';
  $rows = array_chunk($results, 3); // 3 items per row, adjust grid glasses below to center the last one
  foreach ($rows as $stores) {
    if (count($stores) == 3) {
      $gridClasses = 'col-sm-12 col-md-8';
    }
    elseif (count($stores) == 2) {
      $gridClasses = 'col-sm-24 col-md-8 col-md-offset-4';
    }
    else {
      $gridClasses = 'col-sm-24';
    }
      $markup .= '<div class="row">';
          foreach ($stores as $key => $store) {
            // adjust grid classes when we have only two in a row to offset and center below row of 3
            if (count($stores) == 2 && $key == 1) {
              $gridClasses = 'col-sm-24 col-md-8';
            }
              $markup .= '<div class="' . $gridClasses . ' text-center browse-stores"><a href="/browse/category/' . $store->nid . '">';
              $markup .= theme('image_style',array(
                  'style_name' => 'medium',
                  'path' => $store->field_field_image[0]['raw']['uri'],
                  'attributes' => array(
                    'class' => 'center-block',
                    'alt' => $store->node_title,
                  )
                )
              );
              $markup .= '</a></div>';
          }
            $markup .= '</div>';
  }
  $markup .= '</div>';
  return $markup;
}


function virtual_category($storeid, $category) {
  //dpm ($storeid);
  // find out how deep in the taxonomy we are
  $depth = count(taxonomy_get_parents_all($category));
  //dpm($depth);
  // load the store node so we can use misc. values below
  $store = node_load($storeid);
  //dpm($store);

  $troubleTerms = $store->field_trouble_with['und'];

  $troubleTIDs = array();
  foreach ($troubleTerms as $key => $value) {
    $troubleTIDs[] = $value['tid'];
  }

  $troubleTIDs = implode('+', $troubleTIDs);

  //dpm($troubleTIDs);

  $crumbs = array();
  $crumbs[] = l(t('Home'), '');
  $crumbs[] = l(t('Browse Virtual Stores'), 'browse');
  $crumbs[] = l(t($store->title), 'browse/category/' . $storeid);
  if ($depth > 1) {
    $parents = taxonomy_get_parents($category);
    //dpm($parents);
    foreach ($parents as $key => $value) {
      $crumbs[] = l(t($value->name), 'browse/category/' . $storeid . '/' . $value->tid);
    }

  }
  if (is_numeric($category)) {
    $categoryObj = taxonomy_term_load($category);
    $crumbs[] = l(t($categoryObj->name), 'browse/category/' . $storeid . '/' . $category);
  }

  $_SESSION['browse_virtual_stores'] = array();
  $_SESSION['browse_virtual_stores']['crumbs'] = $crumbs;
  $_SESSION['browse_virtual_stores']['troubleTIDs'] = $troubleTIDs;


  array_pop($crumbs);
  $markup = '<nav aria-label="Breadcrumb" class="breadcrumbs">';
  $markup .=  theme('item_list', array(
      'items' => $crumbs,
      'type' => 'ol',
      'attributes' => array('id' => 'main-breadcrumbs', 'class' => array('breadcrumb')),
        )
    );
  $markup .= '</nav>';

  if ($depth > 1) {
    $categoryType = 'shelf';
  }
  else {
    $categoryType = 'section';
  }
  drupal_set_title($categoryObj->name . ': Choose a ' . $categoryType, $output = CHECK_PLAIN);


  if (is_numeric($category)) {

    $vid = 11;
    $units = taxonomy_get_tree($vid, $category, 1, FALSE);
    //dpm($units);
    $resultTotal = 0;
    foreach ($units as $key => $value) {
      //dpm($args);
      $args = array($value->tid, $troubleTIDs);
      $view = views_get_view('browse_shelf');
      $view->set_display('page_1');
      $view->set_arguments($args);
      $view->pre_execute();
      $view->execute();
      $result = $view->result;

      $resultcount = count($result);
      //dpm($resultcount);
      if ($resultcount > 0 && $depth > 1) {
        $unitList[] = l(t($value->name), 'browse/shelf/' . $value->tid) . ' (' . $resultcount . ')';
        $resultTotal = $resultTotal + $resultcount;
      }
      elseif ($resultcount > 0) {
        $unitList[] = l(t($value->name), 'browse/category/' . $storeid . '/' . $value->tid) . ' (' . $resultcount . ')';
        $resultTotal = $resultTotal + $resultcount;
      }
    }

    //dpm($unitList);

    if ($depth > 1) {
      // @@ find the 'others'
      $args = array($category, $troubleTIDs);
      $view = views_get_view('browse_shelf');
      $view->set_display('page_1');
      $view->set_arguments($args);
      $view->pre_execute();
      $view->execute();
      $result = $view->result;

      $children = taxonomy_get_children($category);

      //dpm($args);
      // kpr($result);
      // kpr(array_keys($units));
      $children = array_keys($children);
      //kpr($children);

      foreach ($result as $key => $value) {
        # get the terms on the node and unset the row if we find a match
        //kpr($value->_field_data['nid']['entity']);
        $terms = gpii_saa_custom_get_term_ids($value->_field_data['nid']['entity']);
        $match = array_intersect($children, $terms);
        if (count($match) > 0) {
          unset($result[$key]);
        }
      }

      if ($result > 1) {
        //kpr($result);
        $unitList[] = l(t('Other'), 'browse/shelf/' . $category, array('query' => array('child_categories' => 'none'))) . ' (' . count($result) . ')';
      }

    }

    // if the total number of results we're working with is less than 40, then just skip directly to the shelf
    if ($resultTotal < 40) {
      unset($resultTotal);
      drupal_goto('browse/shelf/' . $category, array('query' => array('child_categories' => 'true')), 302);
    }


    if (count($unitList) === 0) {
        $markup .= '<p>No products are currently available in this sectioon.<p>';
      }


    $markup .= theme('item_list', array(
      'items' => $unitList,
      'type' => 'ul',
      'attributes' => array('id' => 'shelving-units', 'class' => array('unit')),
        )
    );
  }
  // kick out the choose a department image map
  else {

    //drupal_add_js('sites/all/libraries/masonry/masonry.pkgd.min.js');
    drupal_add_js('sites/all/libraries/rwdimagemaps/jquery.rwdImageMaps.min.js');
    drupal_add_js('sites/all/modules/gpii_saa_custom/js/browse-category.js');

    //dpm($store);
    drupal_set_title('Choose a Department in the ' . $title = $store->title . ' Store', $output = CHECK_PLAIN);

    $vid = 11;
    $departments = taxonomy_get_tree($vid, 0, 1, FALSE);

     $markup .= '<map name="storemap">';

    foreach ($departments as $key => $value) {
      // set coordinates and other values related to the generated image map for each top-level item
      switch (true) {
        case $value->tid === '3629': // Adaptive or Assistive Products
          $mapVars = array(
            'coords' => '750,33,1112,359',
            'name' => $value->name,
            'tooltip' => $value->name
          );
          break;
        case $value->tid === '3637': // Computer Access and Use
          $mapVars = array(
            'coords' => '25,164,329,513',
            'name' => $value->name,
            'tooltip' => $value->name
          );
          break;
        case $value->tid === '3639': // Commmunication
          $mapVars = array(
            'coords' => '514,33,739,279',
            'name' => $value->name,
            'tooltip' => $value->name
          );
          break;
        case $value->tid === '3641': // Education
          $mapVars = array(
            'coords' => '749,371,1079,512',
            'name' => $value->name,
            'tooltip' => $value->name
          );
          break;
        case $value->tid === '3648': // Employment/Job
          $mapVars = array(
            'coords' => '566,290,739,513',
            'name' => $value->name,
            'tooltip' => $value->name
          );
          break;
        case $value->tid === '3646': // Daily Living
          $mapVars = array(
            'coords' => '2,34,330,152',
            'name' => $value->name,
            'tooltip' => $value->name
          );
          break;
        case $value->tid === '3634': // Health, Fitness and Sports
          $mapVars = array(
            'coords' => '341,1,501,279',
            'name' => $value->name,
            'tooltip' => $value->name
          );
          break;
        case $value->tid === '4300': // Entertainment and Play
          $mapVars = array(
            'coords' => '341,290,555,544',
            'name' => $value->name,
            'tooltip' => $value->name
          );
          break;
        default:
          // dpm('no dice');
          break;
      }

      $markup .= '<area shape="rect" coords="' . $mapVars['coords'] . '" href="/browse/category/' . $storeid . '/' . $value->tid . '" alt="' . $mapVars['name'] . '" data-toggle="tooltip" data-selector"#departmentmap" title="' . $mapVars['tooltip'] . '" data-template =\'<div class="tooltip" role="tooltip"><div class="tooltip-inner"></div></div>\'>';
    }


    $markup .= '</map>';

    // the image is below the map because Chrome positions data-placement relative to the map element instead of to the image
    $markup .= '<img class="img-responsive" src="/' . drupal_get_path('module', 'gpii_saa_custom') . '/images/ULStoreMapFlat.png" alt="Choose a department" width="1113" height="545" usemap="#storemap" id="departmentmap" />';

  }

  return $markup;
}



function virtual_shelf($tid) {

  // @@ add a condition for "other"
  // Check for tids filter
  //
  //dpm($_GET['child_categories']);

  $markup = '<nav aria-label="Breadcrumb" class="breadcrumbs">';
  $markup .=  theme('item_list', array(
      'items' => $_SESSION['browse_virtual_stores']['crumbs'],
      'type' => 'ol',
      'attributes' => array('id' => 'main-breadcrumbs', 'class' => array('breadcrumb')),
        )
    );
  $markup .= '</nav>';

  // sanitize and verify that we have a valid term id
  check_plain($tid);
  $termObj = taxonomy_term_load($tid);

  //dpm($termObj);

  if ($termObj->tid !== $tid) {
    //dpm('Invalid term ID.');
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


    // get the trouble terms from the session
    $troubleTIDs = $_SESSION['browse_virtual_stores']['troubleTIDs'];

    $args = array($tid, $troubleTIDs);
    $view = views_get_view('browse_shelf');
    $view->set_display('page_1');
    $view->set_arguments($args);
    $view->pre_execute();
    $view->execute();
    $result = $view->result;

    // if this is an "other" shelf, then we need to remove any records that are tagged with child terms
    if($_GET['child_categories'] === 'none') {

      $children = taxonomy_get_children($tid);
      $children = array_keys($children);
      //kpr($children);

      foreach ($result as $key => $value) {
        # get the terms on the node and unset the row if we find a match
        //kpr($value->_field_data['nid']['entity']);
        $terms = gpii_saa_custom_get_term_ids($value->_field_data['nid']['entity']);
        $match = array_intersect($children, $terms);
        if (count($match) > 0) {
          unset($result[$key]);
        }
      }
    }


    //dpm($results);

    $resultCount = count($result);
    if ($resultCount == 1) {
      $shelfItems = 'is ' . $resultCount . ' product';
    }
    else {
      $shelfItems = 'are ' . $resultCount . ' products';
    }
    $markup .= '<p>There ' . $shelfItems . ' on this shelf.</p>';

    if ($resultCount > 0) {
      $markup .= <<<END
      <div class="container" id="flexslider-wrap">
        <div class="row">
          <div class="col-md-1 flex-preface"><p class="sr-only">Start Shelf</p></div>
          <div class="flexslider col-md-22">
            <ul class="slides">

END;

      foreach ($result as $key => $value) {
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
      // Add a next shelf button below
      // <li>@@ next shelf button</li>
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
