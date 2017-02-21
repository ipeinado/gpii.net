(function($) {

Drupal.behaviors.popular_tags = {
  attach: function(context, settings) {
    $('.popular-tags .tag-terms .term', context).click(function(event) {
      $this = $(this);
      var inp = $this.parents('.form-item').find('input:text.form-text');
      var val = inp.val();
      var term = $this.text();
      if(val.indexOf(term) == 0) {
        return false;
      }
      if(val.indexOf(', ' + term) >= 0) {
        return false;
      }
      if(val) {
        inp.val(val + ', ' + term);
      } else {
        inp.val(term);
      }
      return false;
    });
    console.log(Drupal.settings.popular_tags);
    if(Drupal.settings.popular_tags) {
      for(field_name in Drupal.settings.popular_tags) {
        var field_name = field_name.replace(/_/g, '-');
        console.log(field_name);
        var field_container = $('.form-item-' + field_name + '-und', context);
        var tag_container = field_container.find('.popular-tags');
        var show = tag_container.find('a.show-all-terms');
        var hide = tag_container.find('a.show-popular-terms');
        show.click({hide: hide, tag_container: tag_container}, function(ev) {
          $(this).hide();
          ev.data.hide.show();
          ev.data.tag_container.find('.term').not('.popular').show();
          return false;
        });
        hide.click({show: show, tag_container: tag_container}, function(ev) {
          $(this).hide();
          ev.data.show.show();
          ev.data.tag_container.find('.term').not('.popular').hide();
          return false;
        });
        hide.click();
      }
    }
  }
}

})(jQuery);
