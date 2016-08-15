
-- Summary --

The "facetapi views" module integrates the facet api into views.
Main goal is to provide a connection between the views exposed filters and the
facets.


-- Features --

* Keep selected facets when changing views exposed filters.
* Use views filters to preset facet links


-- Requirements --

facetapi & views


-- Installation

* Install as usual, see following link for further information:
  http://drupal.org/documentation/install/modules-themes/modules-7


-- Configuration

* Configure the facetapi filter in the views where you'd like to keep the facets
  when changing the views exposed filter.
* Configure the URL processor for facetapi to use views filters to preset the
  facets.


-- Credits

Source Issue: http://drupal.org/node/1797616
* mErilainen for the URL processor - see his blog post:
  http://wunderkraut.com/blog/marrying-facets-and-exposed-filters/2012-10-24
* Soul88 for the intial views code - see his sandbox:
  http://drupal.org/sandbox/Soul88/1865682
* das-peter for merging and polishing both approaches into one module ;)

