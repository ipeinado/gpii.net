<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

// /**
// * hook_form_FORM_ID_alter
// */
// function gpii_devspace_form_alter(&$form, &$form_state, $form_id) {
// 	switch ($form['#form_id']) {
// 		case 'search_api_page_search_form_search':
// 			$form['keys_1']['#attributes']['placeholder'] = t('Search components, bibliography, techniques, etc.');
// 			$form['keys_1']['#size'] = 24;
// 			$form['submit_1']['#value'] = '<i class="fa fa-search" aria-hidden="true"></i> <span class="sr-only">Search</span>';
// 			break;	
// 	}
// }

/**
* Preprocess the wrapping HTML
*
* @param array &$variables
*/
function gpii_devspace_preprocess_html(&$vars) {
	// Setup Google Webmasters Verification Meta Tag
	$google_webmasters_verification = array(
		'#type' => 'html_tag',
		'#tag' => 'meta',
		'#attributes' => array(
			'name' => 'google-site-verification',
			'content' => 'zFHqFXEns79WsfjFrNGvDBrw9HGgG53j1IVf86fnMDg'
		),
	);

	// Add Google Webmasters Verification Meta Tag to head.
	drupal_add_html_head($google_webmasters_verification, 'google_webmasters_verification');
}

function gpii_devspace_preprocess_page(&$variables) {
	if (arg(1) == '3243') {
		drupal_add_js(drupal_get_path('theme', 'gpii_devspace') . '/js/masterlist.js');
	}
}