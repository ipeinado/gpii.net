/* set Find Similar Products select2 widget to open and recieve focus on page load */

(function ($) {
  'use strict';

  $(window).load(function(){
    $('.use-select-2').select2('open');
    $('.select2-search__field').focus();
    
  });

}(jQuery));
