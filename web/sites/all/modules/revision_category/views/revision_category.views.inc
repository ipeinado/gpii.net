<?php

/**
 * Implements hook_views_data_alter().
 *
 * Here we define pseudo-fields for the {node} and {node_revision} tables.
 */
function revision_category_views_data_alter(&$data) {
    $data['node_revision']['category'] = array(
        'title' => t('Category'),
        'help' => t('The category of the edit made in the revision.'),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        )
    );
}