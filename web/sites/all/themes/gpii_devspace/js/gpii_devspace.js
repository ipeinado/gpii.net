(function($) {
	$(document).ready(function() {
		var title = $('.page-header').text();
		$('[data-title="' +  title + '"]').addClass('selected');
	});
})(jQuery);