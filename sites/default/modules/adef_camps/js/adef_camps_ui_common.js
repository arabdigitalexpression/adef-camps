(function ($) {
  Drupal.adefCamps = {};

  Drupal.adefCamps.formatSchedule = function (container, zoomLevel, daysToShow) {
    sessions = $(container).children();
    scheduleParams = Drupal.adefCamps.getScheuleParams(sessions);

    var fullWidth = $(container).width() - $(sessions).first().width();
    var newRow = true;
    var currentDayCode = "";
    var zoomFactor = 2;
    if (zoomLevel == 1) {
      zoomFactor = fullWidth / (scheduleParams.dayLength * daysToShow);
    } else {
      var fullWidthWithHeader = (scheduleParams.dayLength * daysToShow * zoomFactor) + $(sessions).first().width();
      $(container).parent().outerWidth(fullWidthWithHeader);
    }
    var dayCredit = 0;

    $(sessions).each(function () {
      if ($(this).prop('tagName') == 'H3') {
        newRow = true;
      } else {
        var dayRowShift = 0;
        var time = String($(this).data('start'));// Drupal.adefCamps.getClassData($(this), 'start');
        var slotStart = Drupal.adefCamps.timeToMinutes(time) - scheduleParams.earliest;
        var slotWidth = parseInt($(this).data('duration'));
        dayCode = String($(this).data('daycode'));
        if (dayCode != currentDayCode) { //new day
          if (!newRow) { //same row
            dayRowShift = (scheduleParams.dayLength - dayCredit);
          }
          dayCredit = 0;
          currentDayCode = dayCode;
        }
        if (newRow) {
          dayCredit = 0;
          newRow = false;
        }
        slotStart -= dayCredit;
        $(this).css("margin-right", (slotStart + dayRowShift) * zoomFactor + "px").outerWidth((slotWidth * zoomFactor) - 5); //need to use outerWidth properly with no manual padding calculation
        dayCredit += (slotWidth + slotStart);
      }

    });
    return true;
  };

  Drupal.adefCamps.getScheuleParams = function (sessions) {
    var earliest = "2359";
    var latest = 0;
    var dayLength = 0;
    var currentDay = 0;
    $(sessions).each(function () {
      if ($(this).prop('tagName') != 'H3') {
        time = String($(this).data('start'));
        timeInMinutes = Drupal.adefCamps.timeToMinutes(time);
        timeToEnd = timeInMinutes + parseInt($(this).data('duration'));
        if (time < earliest) {
          earliest = time;
        }
        if (timeToEnd > latest) {
          latest = timeToEnd;
        }
      }
    });

    earliest = Drupal.adefCamps.timeToMinutes(earliest);
    dayLength = latest - earliest;

    return {'earliest': earliest, 'latest': latest, 'dayLength': dayLength};
  };

  Drupal.adefCamps.getClassByPrefix = function (item, prefix) {
    classes = $(item).prop('class').split(" ");
    for (var i = 0; i < classes.length; i++) {
      if (classes[i].indexOf(prefix) == 0) {
        return classes[i];
      }
    }
    return '';
  };

  Drupal.adefCamps.getClassData = function (item, prefix, defaultValue) {
    if (!defaultValue) {
      defaultValue = 0
    }
    ;
    var theClass = Drupal.adefCamps.getClassByPrefix(item, prefix);
    var value = theClass.substring(theClass.indexOf('-') + 1, theClass.length);
    if (value == '') {
      value = defaultValue;
    }
    return value;
  };

  Drupal.adefCamps.timeToMinutes = function (timeString) {
    if (timeString.length != 4) {
      return 0;
    }
    var mins = (parseInt(timeString.substr(0, 2)) * 60) + parseInt(timeString.substr(2, 2));
    return mins;
  };

}(jQuery));
