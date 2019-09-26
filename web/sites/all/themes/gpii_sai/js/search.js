(function($) {
  'use strict';

  $(document).ready(function() {
    // Add page loading element
    $('body.page-search').append(
      '<div class="fullpage-loading"><div class="lds-dual-ring"></div></div>'
    );

    // Event for submit and facet filters to pull up the full screen overlay
    $('.views-exposed-form,' + '.facetapi-facetapi-checkbox-links,' + '#block-current-search-standard').on(
      'click keypress',
      'input:not([type^="text"]), a, .clear-button, #edit-submit-search',
      function() {
        $('.fullpage-loading').show();
      }
    );

    // Check for the presence of any active query and no previously saved keywords. Hide the results and pager if not found
    var url = window.location.search;

    if (url.length === 0 && !$('#edit-search-api-views-fulltext').val()) {
      $('.view-search #block-block-2 ~ .view-results, ul.pagination, #block-block-2 .remote-filters').remove();
      $('.view-search:not(.view-display-id-page_2) .st-search h2.resultcount').text('0 Results');
      $('.view-search:not(.view-display-id-page_2) .st-search .resultcount h2').text('0 Results');   
      $('.view-search.view-display-id-page_2 .st-search .resultcount').addClass('nextsteps');
      $('.view-search.view-display-id-page_2 .st-search .resultcount').remove();
    }

    // Event for Dropdowns
    $('#block-block-2 .remote-wrapper ul').on('click', 'a', function() {
      var wrapper = $(this).parents('.remote-wrapper');
      var button = wrapper.children('button');
      var label = $(this).text();
      button.children('.current-value').text(label);

      var target = $('.views-exposed-form #' + button.attr('data-edit'));
      var value = $(this).attr('value');
      var order = 'DESC';
      if (wrapper.hasClass('remote-sort-by')) {
        if (value == 'search_api_aggregation_2') {
          order = 'ASC';
        }
        $('#block-block-2 .remote-sort-order span.current-value').text('Ascending');
        $('.views-exposed-form #edit-sort-order').val(order);
      }
      target.val(value).trigger('change');
      // since results per page doesn't support auto-submit, we also have to click the search button here
      $('.views-exposed-form #edit-submit-search').trigger('click');
    });

    // Event for Checkboxes
    $('#block-block-2 .checkbox').on('change', 'input', function() {
      var wrapper = $(this).parents('.remote-wrapper');
      var checkbox = wrapper.find('input');
      if (wrapper.hasClass('remote-show-discontinued')) {
        if (checkbox.is(':checked')) {
          $('.views-exposed-form #edit-product-status-2').trigger('click');
        } else {
          $('.views-exposed-form #edit-product-status-1').trigger('click');
        }
      }
    });

    // Event for Buttons
    $('#block-block-2 button:not(.dropdown-toggle)').on('click', function() {
      $('#' + $(this).attr('data-edit')).trigger('click');
    });

    // set the initial values
    $('#block-block-2 .remote-sort-by span.current-value').html(
      $('.views-exposed-form #edit-sort-by option:selected').text()
    );
    $('#block-block-2 .remote-sort-order span.current-value').html(
      $('.views-exposed-form #edit-sort-order option:selected').text()
    );
    $('#block-block-2 .remote-items-per-page span.current-value').html(
      $('.views-exposed-form #edit-items-per-page').val()
    );
    if ($('.views-exposed-form #edit-product-status-2').is(':checked')) {
      $('#block-block-2 .remote-show-discontinued input').prop('checked', true);
    }
  });
})(jQuery);
