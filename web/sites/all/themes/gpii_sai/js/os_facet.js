var parseQueryString = function(queryString) {
  var params = [],
    queries,
    temp,
    i,
    l;
  // Split into key/value pairs
  queries = queryString.split('&');
  // Convert the array of strings into an object
  for (i = 0, l = queries.length; i < l; i++) {
    temp = queries[i].split('=');
    params[temp[0]] = temp[1];
  }
  return params;
};

var url = window.location.href.split('?');
var base_url = url[0];
var query = decodeURIComponent(url[1]);

(function($) {
  'use strict';

  $(document).ready(function() {
    //Adding custom elements to Operating Systems facet filter block
    var helpText =
      '<p>Show <strong>only</strong> products that are compatible with the following operating systems.</p>';
    var clearButton =
      '<p><button class="btn btn-default btn-sm clear-button">Clear Selected Operating Systems</button></p>';

    $('.facetapi-facet-field-operating-system').before(helpText, clearButton);

    // Remove all facet related GET params from url and request
    $('.block-facetapi .clear-button').on('click', function(e) {
      var params = parseQueryString(query);
      var reg = /field_operating_system/;
      Object.keys(params).forEach(function(key) {
        let value = params[key];
        if (reg.test(value)) {
          delete params[key];
        }
      });
      var new_query = Object.keys(params)
        .map(function(key) {
          return key + '=' + params[key];
        })
        .join('&');
      location.href = base_url + '?' + new_query;
    });
  });
})(jQuery);
