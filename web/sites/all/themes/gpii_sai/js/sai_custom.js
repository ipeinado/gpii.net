/*jslint browser: true*/
/*global jQuery*/

(function ($) {
  'use strict';

  // Tag the body when viewed in IE to fix some style issues.
  $(document).ready(function(){
    $('.highlighted .panel')
    .on('click', function() {
      window.location.href = $(this)
        .find('.content a[href]')
        .first()
        .attr('href');
    });

    // Since we can't find the module that is setting role="application", 
    // switch the exposed form for standard search to use a better role
    $('.form-item-search-api-views-fulltext').attr('role', 'search');
  });

}(jQuery));
