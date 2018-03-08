(function($) {
	$(document).ready(function() {
		var selectedNeed = "";
		
		function resetFilters() {
			console.log("Resetting filters");
			selectedNeed = "";
			$('.filter-button').removeClass('selected');
			$('.filter-button').attr('aria-checked', 'False');
			$('.technique').show();
		}

		function filterNeeds() {
			console.log(selectedNeed);
			var techniques = $('.technique');
			techniques.each(function() {
				var needs_string = $(this).data("needs");
				var needs_array = needs_string.split(", ");
				if (needs_array.indexOf(selectedNeed) < 0) {
					$(this).hide();
				}
			});
		}

		$(".filter-button").click(function(e) {
			e.stopPropagation();
			selectedNeed = $(this).data('need');
			resetFilters();
			if ($(this).attr('aria-checked') == 'True') {
				$(this).attr('aria-checked', 'False');
				$(this).removeClass('selected');
			} else {
				$(this).attr('aria-checked', 'True');
				$(this).addClass('selected');
				selectedNeed = $(this).data('need');
				filterNeeds();
			}
		});

		$('#reset-filters').click(function(e) {
			e.stopPropagation();
			resetFilters();
		});

	});
})(jQuery);