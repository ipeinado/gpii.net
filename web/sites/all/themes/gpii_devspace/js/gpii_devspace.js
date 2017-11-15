(function($) {
	$(document).ready(function() {
		var title = $('.page-header').text();
		$('[data-title="' +  title + '"]').addClass('selected');

		$('.search-toggle').click(function(e) {
			e.preventDefault();
			let searchBox = $('#search-box');
			if (searchBox.attr('aria-expanded') == 'false') {
				$(this).attr('aria-pressed', 'true');
				searchBox.slideDown('fast', function() {
					$(this).attr('aria-expanded', 'true');
					$('#edit-keys-1').focus();
				});
			} else {
				$(this).attr('aria-pressed', 'false');
				searchBox.slideUp('fast', function() {
					$(this).attr('aria-expanded', 'false');
				});
			}
		});
	});
})(jQuery);

