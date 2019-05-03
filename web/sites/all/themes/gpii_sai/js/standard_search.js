var parseQueryString = function( queryString ) {
    var params = [], queries, temp, i, l;
    // Split into key/value pairs
    queries = queryString.split("&");
    // Convert the array of strings into an object
    for ( i = 0, l = queries.length; i < l; i++ ) {
        temp = queries[i].split('=');
        params[temp[0]] = temp[1];
    }
    return params;
};

var url = window.location.href.split('?')
var base_url = url[0];
var query = decodeURIComponent(url[1]);

(function ($) {
    'use strict';

    $(document).ready(function(){

        // Check for the presence of any active query and no previously saved keywords. Hide the results and pager if not found
        var url = window.location.search;
        if (url.length === 0 && !$('#edit-search-api-views-fulltext').value ) {
            $('.view-search .view-results, ul.pagination, #block-block-2 .remote-filters').remove();
            $('.st-search h2.resultcount').text('0 Results');
            $('#block-block-2').append('<p style="margin-top: 0.5rem">Please enter one or more search terms to start your search.</p>');
            
        }


        $('body.page-search').append('<div class="fullpage-loading"><div class="lds-dual-ring"></div></div>');

        //Adding custom elements to Operating Systems facet filter block
        var helpText = '<p>Show <strong>only<\/strong> products that are compatible with the following operating systems.</p>';
        var clearButton = '<p><button class="btn btn-default btn-sm clear-button">Clear Selected Operating Systems</button></p>';

        $('.facetapi-facet-field-operating-system').before(helpText, clearButton);

        // Remove all facet related GET params from url and request
        $('.block-facetapi .clear-button').on('click', function (e) {
            var params = parseQueryString(query);
            var reg = /field_operating_system/;
            Object.keys(params).forEach(key => {
                let value = params[key];
                if (reg.test(value)) {
                    delete params[key];
                }
            });
            var new_query = Object.keys(params).map(key => key + '=' + params[key]).join('&');
            location.href = base_url + "?" + new_query;
        });

        // Event for Dropdowns
        $('#block-block-2 .remote-wrapper ul').on('click', 'a', function() {
            var wrapper = $(this).parents('.remote-wrapper');
            var button = wrapper.children('button');
            var label = $(this).text();
            button.children('.current-value').text(label);
            
            var target = $("#views-exposed-form-search-page #" + button.attr('data-edit'));
            var value = $(this).attr('value');
            var order = 'DESC';
            if (wrapper.hasClass('remote-sort-by')) {
                if (value == 'search_api_aggregation_2') {
                    order = 'ASC';
                }
                $('#block-block-2 .remote-sort-order span.current-value').text('Ascending');
                $('#views-exposed-form-search-page #edit-sort-order').val(order);
               
            }
            $('.fullpage-loading').show();
            target.val(value).trigger('change');
            // since results per page doesn't support auto-submit, we also have to click the search button here
            $('#views-exposed-form-search-page #edit-submit-search').trigger('click'); 

        });

        // Event for Checkboxes
        $('#block-block-2 .checkbox').on('change', 'input', function() {
            var wrapper = $(this).parents('.remote-wrapper');
            var checkbox = wrapper.find('input');
            if (wrapper.hasClass('remote-show-discontinued')) {
                $('.fullpage-loading').show();
                if (checkbox.is(':checked')) {
                    
                    $('#views-exposed-form-search-page #edit-product-status-2').trigger('');
                }
                else {
                    $('#views-exposed-form-search-page #edit-product-status-1').trigger('click');
                }
            }
        });

        // Event for Buttons
        $('#block-block-2 button:not(.dropdown-toggle)').on('click', function() {
            $('.fullpage-loading').show();
            $("#" + $(this).attr('data-edit')).trigger('click');
        });

        // Event for submit and facet filters to pull up the full screen overlay
        $('#views-exposed-form-search-page #edit-submit-search, .facetapi-facetapi-checkbox-links input, .facetapi-facetapi-checkbox-links a, .clear-button, #block-current-search-standard a').on('click keypress', function() {
            $('.fullpage-loading').show();
        });

        // set the initial values
        $('#block-block-2 .remote-sort-by span.current-value').html($('#views-exposed-form-search-page #edit-sort-by option:selected').text());
        $('#block-block-2 .remote-sort-order span.current-value').html($('#views-exposed-form-search-page #edit-sort-order option:selected').text());
        $('#block-block-2 .remote-items-per-page span.current-value').html($('#views-exposed-form-search-page #edit-items-per-page').val());
        if ($('#views-exposed-form-search-page #edit-product-status-2').is(':checked')) {
            $('#block-block-2 .remote-show-discontinued input').prop('checked', true);
        }
    });

}(jQuery));