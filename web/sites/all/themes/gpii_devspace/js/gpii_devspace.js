(function($) {
	$(document).ready(function() {
		var title = $('.page-header').text();
		$('[data-title="' +  title + '"]').addClass('selected');

		$(".search-button").click(function(e) {
			e.preventDefault();
			let btn = $(this);
			if ($(this).attr('aria-pressed') === 'true') {
				$('.region-search-box').slideUp('fast', function() {
					btn.attr('aria-pressed', 'false');
				});
			} else {
				$('.region-search-box').slideDown('fast', function() {
					$('#edit-keys-1').focus();
					btn.attr('aria-pressed', 'true');
				});
			}
		});
	});
})(jQuery);