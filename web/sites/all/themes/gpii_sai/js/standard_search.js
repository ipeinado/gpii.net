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

        // Adding custom elements to Operating Systems facet filter block
        var helpText = '<p>Show <strong>only<\/strong> products that are compatible with the following operating systems.</p>';
        var clearButton = '<a class="btn btn-default btn-xs clear-button" role="button">Clear Operating Systems</a>';

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
            
            var target = $("#block-views-exp-search-page #" + button.attr('data-edit'));
            var value = $(this).attr('value');
            var order = 'DESC';
            if (wrapper.hasClass('remote-sort-by')) {
                if (value == 'search_api_aggregation_2') {
                    order = 'ASC';
                }
                $('#block-block-2 .remote-sort-order a[value="' + order + '"]').trigger('click');
            }
            target.val(value).trigger('change');

        });

        // Event for Checkboxes
        $('#block-block-2 .checkbox').on('change', 'input', function() {
            var wrapper = $(this).parents('.remote-wrapper');
            var checkbox = wrapper.find('input');
            if (wrapper.hasClass('remote-show-discontinued')) {
                if (checkbox.is(':checked')) {
                    $('#block-views-exp-search-page #edit-field-status-2').trigger('click');
                }
                else {
                    $('#block-views-exp-search-page #edit-field-status-1').trigger('click');
                }
            }
        });

        // Event for Buttons
        $('#block-block-2 button:not(.dropdown-toggle)').on('click', function() {
            $("#" + $(this).attr('data-edit')).trigger('click');
        });

        // set the initial values
        $('#block-block-2 .remote-sort-by a[value="' + $('#block-views-exp-search-page #edit-sort-by').val() + '"]').trigger('click');
        $('#block-block-2 .remote-sort-order a[value="' + $('#block-views-exp-search-page #edit-sort-order').val() + '"]').trigger('click');
        $('#block-block-2 .remote-items-per-page a[value="' + $('#block-views-exp-search-page #edit-items-per-page').val() + '"]').trigger('click');
        if ($('#block-views-exp-search-page #edit-field-status-2').is(':checked')) {
            $('#block-block-2 .remote-show-discontinued').trigger('click');
        }
    });

}(jQuery));