(function ($) {

  Drupal.behaviors.alter_flag_links = {
    attach: function(context) {
      $('[class*="flag-photo"], [class*="flag-alt"], [class*="flag-description"], [class*="flag-mfgr"], [class*="flag-tax"], [class*="flag-where"]').each(function() {
        var flag_link = $(this).children('a');
        if (flag_link.length) {
          flag_link.hide();
          var class_attr = 'flag-cb';
          var checked = (flag_link.hasClass('unflag-action')) ? true : false;
          if (!$(this).children('input').length) {
            var checkbox = $('<input type="checkbox" />').attr({'checked': checked, 'class': class_attr, 'title': flag_link.text()});
            $(this).prepend(checkbox);
          }
        }
      });

      $('input.flag-cb').click(function() {
        $(this).siblings('a').click();
      });
    }
  };

}(jQuery));
