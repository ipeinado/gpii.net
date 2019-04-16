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

        // set the initial values
        $('#block-block-2 #edit-sort-by').val($('#block-views-exp-search-page #edit-sort-by').val());
        $('#block-block-2 #edit-sort-order').val($('#block-views-exp-search-page #edit-sort-order').val());
        $('#block-block-2 #edit-items-per-page').val($('#block-views-exp-search-page #edit-items-per-page').val());
        if ($('#block-views-exp-search-page #edit-field-status-2').is(':checked')) {
            $('#block-block-2 #edit-show-discontinued').prop('checked', true);
        }

        // change values when changed by user
        $('#block-block-2 select, #block-block-2 input').on('change', function() {
            var filter_id = $(this).attr('id');
            if (filter_id == 'edit-show-discontinued') {
                if ($(this).is(':checked')) {
                    $('#block-views-exp-search-page #edit-field-status-1').prop('checked', false);
                    $('#block-views-exp-search-page #edit-field-status-2').prop('checked', true);
                }
                else {
                    $('#block-views-exp-search-page #edit-field-status-1').prop('checked', true);
                    $('#block-views-exp-search-page #edit-field-status-2').prop('checked', false);
                }
            }
            else {
                $('#block-views-exp-search-page #' + filter_id).val($(this).val());
            }
        });
    });

}(jQuery));