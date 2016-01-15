(function ($) {

Drupal.behaviors.book_explorer = {
  attach: function() {
    function selector_activate(control) {
      $(control).find('span').text('Collapse section: ' + control.link_text);
      $(control.menu).slideDown();
      $(control).removeClass('book-explorer-collapsed').addClass('book-explorer-expanded');
      control.expanded = true;
    }

    function selector_deactivate(control) {
      $(control).find('span').text('Expand section: ' + control.link_text);
      var selector = '>ul, .book-explorer-markup, :not(.book-explorer-markup) > li > ul';
      $(selector, control.list_item).slideUp();
      $('.book-explorer-toggle', control.list_item).each(function () { 
        this.expanded = false; 
      }).removeClass('book-explorer-expanded').addClass('book-explorer-collapsed');
      $(control).removeClass('book-explorer-expanded').addClass('book-explorer-collapsed');
      control.expanded = false;
    }
    
    $('.book-explorer').once().each(function () {
      $('.expanded', this).each(function () {
        var list_item = this;
        var link_text = $('> a',this).text()
        $('<a href="#" class="book-explorer-toggle"><span class="sr-only">Toggle section: '+link_text+'</span></a>').prependTo(this).each(function () {
          this.list_item = list_item;
          this.link_text = link_text;
          if ($('a.active', list_item).length) {
            this.menu = $('>ul, >div', list_item);
            $(this).addClass('book-explorer-expanded');
            this.expanded = true;
          }
          else {
            this.menu = $('>ul, >div', list_item).hide();
            $(this).addClass('book-explorer-collapsed');
            this.expanded = false;
          }
          $(this).click(function () {
            if (this.expanded) {
              selector_deactivate(this);
            }
            else {
              selector_activate(this);
            }
            return false;
          });
        });
      });
    });
  }
};

})(jQuery);
