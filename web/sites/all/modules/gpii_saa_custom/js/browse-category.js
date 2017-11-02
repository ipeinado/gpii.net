/*jslint browser: true*/
/*global jQuery*/

(function ($) {
  'use strict';

  $(document).ready(function(){
    // $('.grid').masonry({
    //   itemSelector: '.grid-item',
    //   columnWidth: '.grid-sizer',
    //   percentPosition: true,
    //   gutter: 10
    // });
    $('img[usemap]').rwdImageMaps();
  });

}(jQuery));
