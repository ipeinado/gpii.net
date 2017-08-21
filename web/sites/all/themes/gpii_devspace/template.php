<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

/**
* hook_form_FORM_ID_alter
*/
function gpii_devspace_form_alter(&$form, &$form_state, $form_id) {
	switch ($form['#form_id']) {
		case 'search_api_page_search_form_search':
			$form['keys_1']['#attributes']['placeholder'] = t('Search DeveloperSpace');
			$form['keys_1']['#size'] = 24;
			$form['submit_1']['#value'] = '<i class="fa fa-search" aria-hidden="true"></i> <span class="sr-only">Search</span>';
			break;	
	}
	
}