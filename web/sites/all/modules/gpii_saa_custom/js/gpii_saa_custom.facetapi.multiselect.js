Drupal.behaviors.gpii_saa_customFacetApiMultiselectWidget = {
  attach: function (context, settings) {
    // Go through each facet API multiselect element that is being displayed.
    jQuery('.facetapi-multiselect', context).each(function () {
      // Attach the behavior to it.
      jQuery(this).multiselect({
        // Pass in whatever array of options you need here.
        //header: "Choose an Option!", // enabling this causes check all options to be hidden
        show: ["fold", 200],
        hide: ["fold", 1000],
        height: 'auto',
        selectedList: 4, // 0-based index
        position: {
          my: 'left top',
          at: 'left bottom',
          collision: 'fit flip'
        }
      });
    });
  }
};
