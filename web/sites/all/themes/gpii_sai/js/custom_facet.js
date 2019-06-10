(function($) {
  'use strict';

  // functions below have been pulled from the facetapi.js and modified for wanted behavior.
  var Redirect = function(href) {
    this.href = href;
  };

  Redirect.prototype.gotoHref = function() {
    window.location.href = this.href;
  };

  function makeCheckboxes(facet_id) {
    var $facet = $('#' + facet_id),
      $links = $('a.facetapi-checkbox', $facet);

    // Find all checkbox facet links and give them a checkbox.
    $links.once('facetapi-makeCheckbox').each(makeCheckbox);
  }

  function makeCheckbox() {
    var $link = $(this),
      active = $link.hasClass('facetapi-active');

    if (!active && !$link.hasClass('facetapi-inactive')) {
      // Not a facet link.
      return;
    }

    // Derive an ID and label for the checkbox based on the associated link.
    // The label is required for accessibility, but it duplicates information
    // in the link itself, so it should only be shown to screen reader users.
    var id = this.id + '--checkbox',
      description = $link.find('.element-invisible').html(),
      label = $('<label class="element-invisible" for="' + id + '">' + description + '</label>'),
      checkbox = $('<input type="checkbox" class="facetapi-checkbox" id="' + id + '" />'),
      // Get the href of the link that is this DOM object.
      href = $link.attr('href'),
      redirect = new Redirect(href);

    checkbox.click(function(e) {
      redirect.gotoHref();
    });

    if (active) {
      checkbox.attr('checked', true);
      // Add the checkbox and label.
      $link.before(label).before(checkbox);
    } else {
      $link.before(label).before(checkbox);
    }
  }

  $(document).ready(function() {
    makeCheckboxes('block-block-3');
    makeCheckboxes('block-block-4');
  });
})(jQuery);
