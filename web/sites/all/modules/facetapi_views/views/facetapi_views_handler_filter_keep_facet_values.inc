<?php

/**
 * @file
 * Facet API views integration - filter to keep the set facets.
 */

/**
 * Filter to keep the set facets.
 *
 * @ingroup views_filter_handlers
 */
class facetapi_views_handler_filter_keep_facet_values extends views_handler_filter {

  /**
   * Remove expose option from options form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['expose_button']);
  }

  /**
   * Has no summary.
   */
  public function admin_summary() {
    return '';
  }

  /**
   * Always exposed.
   */
  public function can_expose() {
    return TRUE;
  }

  /**
   * Always expose.
   */
  public function is_exposed() {
    return TRUE;
  }

  /**
   * Ensure we don't modify the query.
   */
  public function query() {}

  /**
   * No need for output here.
   */
  public function render($empty = FALSE) {}

  /**
   * This doesn't output the facet fields but a placeholder for later injection.
   *
   * We can't output the hidden fields here because at that point it's not sure
   * that facetapi_get_active_searchers() will provide the necessary
   * information. This due the fact that the exposed form handling takes place
   * before the views query is run. And only with the query run we might get the
   * searcher related to this view.
   *
   * @see facetapi_get_active_searchers()
   */
  public function exposed_form(&$form, &$form_state) {
    $form['facetapi_keep_facets_placeholder'][] = array(
      '#pre_render' => array('facetapi_views_exposed_form_pre_render'),
    );
  }

}
