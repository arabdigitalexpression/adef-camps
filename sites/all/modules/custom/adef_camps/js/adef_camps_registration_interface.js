(function ($) {
  var timer;
  timer = setInterval(getSlots, 10000);
  getSlots();
  $().ready(function () {
    //prepare sessions interaction
    Drupal.adefCamps.formatSchedule('#available-sessions .view-content', 2, adefCampsDaysToShow, adefCampsStartDate);
    $('.tooltip').hide();
    $('.session').mouseover(function () {
      if (getClassByPrefix($(this), 'id-') == 'id-') {
        return;
      }
      $('.' + getClassByPrefix($(this), 'id-')).addClass('repeated');
      if ($('.' + getClassByPrefix($(this), 'w-') + '.selected').length == 0) {
        $('.' + getClassByPrefix($(this), 'w-')).not('.' + getClassByPrefix($(this), 'id-')).addClass('required');
      }
      $(this).removeClass('repeated');
      if (!$(this).hasClass('disabled')) {
        $(this).children('.tooltip').show().children().show();
      }
    }).mouseleave(function () {
      $('.' + getClassByPrefix($(this), 'id-')).removeClass('repeated');
      if ((!$(this).hasClass('selected')) && $('.' + getClassByPrefix($(this), 'w-') + '.selected').length == 0) {
        $('.' + getClassByPrefix($(this), 'w-')).removeClass('required');
      }
      $(this).children('.tooltip').hide();
    }).click(function () {
      if (getClassByPrefix($(this), 'id-') == 'id-') {
        return;
      }
      if ($(this).hasClass('disabled') && !($(this).hasClass('selected'))) {
        return;
      }
      if ($(this).hasClass('selected')) {
        $(this).removeClass('selected');
        timeOverlap(this, false);
        //$('.' + getClassByPrefix($(this), 'tc-')).removeClass('disabled');
        if ($('.' + getClassByPrefix($(this), 'w-') + '.selected').not('.' + getClassByPrefix($(this), 'id-')).length > 0
                && $('.' + getClassByPrefix($(this), 'id-') + '.selected').length == 0) {
          $('.' + getClassByPrefix($(this), 'id-')).addClass('required');
        }
      } else {
        timeOverlap(this, true);
        //$('.' + getClassByPrefix($(this), 'tc-')).addClass('disabled');
        $(this).addClass('selected');
        $('.' + getClassByPrefix($(this), 'id-')).removeClass('required');
      }
      updateSelected();
    }); //finished prepare sessions interaction

    //deal with selected sessions
    selected = $('input[name=timespace]').val();
    selected_array = selected.split(',');
    for (var i = 0; i < selected_array.length; i++) {
      $('.session.zkid-' + selected_array[i]).click();
    }
    //resize container to fit width of schedule for scrolling
//    firstLocation = $('#available-sessions h3').first();
//    slotsInLocation = firstLocation.nextUntil('h3','.session');
//    totalWidth = firstLocation.outerWidth();
//    for (i=0;i < slotsInLocation.length;i++) {
//      totalWidth += $(slotsInLocation[i]).outerWidth();
//    }
//    $('#available-sessions div.view').width(totalWidth);
  });

  function getClassByPrefix(item, prefix) {
    classes = $(item).prop('class').split(" ");
    for (var i = 0; i < classes.length; i++) {
      if (classes[i].indexOf(prefix) == 0) {
        return classes[i];
      }
    }
    return '';
  }

  function timeOverlap(session, disable) {
    $('.session[data-daycode = "' + $(session).data('daycode') + '"]').each(function (pos, testSession) {
      sessionStart = $(session).data('startts');
      sessionEnd = $(session).data('endts');
      testSessionStart = $(testSession).data('startts');
      testSessionEnd = $(testSession).data('endts');
      if ((sessionStart < testSessionEnd) && (sessionEnd > testSessionStart)) {
        if (disable) {
          $(testSession).addClass('disabled');
        } else {
          $(testSession).removeClass('disabled');
        }
      }
    });
  }

  function updateSelected() {
    var selected = new Array();
    $('.session.selected').each(function (pos, session) {
      cssclasses = $(session).prop('class').split(' ');
      for (i = 0; i < cssclasses.length; i++) {
        zkid = '';
        if (cssclasses[i].substr(0, 11) == 'zkid') {
          zkid = cssclasses[i].replace('zkid-', '');
        }
      }
      selected[pos] = zkid;
    })
    $('input[name=timespace]').val(selected.toString());
  }

  function getSlots() {
    var url = '/?q=adefcamps/registration/slots';
    $.getJSON(url, function (json) {
      $.each(json, function (key, val) {
        if (val > 0) {
          message = Drupal.t("Remaining slots: @slots", {"@slots": val});
        } else {
          message = Drupal.t("No slots");
        }
        $('.zkid-' + key + ' .slots').html(message);
      });
    });
  }
}(jQuery));