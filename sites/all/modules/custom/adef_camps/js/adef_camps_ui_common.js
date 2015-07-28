(function ($, Drupal) {
  Date.prototype.getMonthName = function () {
    month_names = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'];
    return month_names[this.getMonth()];
  }

  Date.prototype.getWeekdayName = function () {
    month_names = ['Sunday', 'Monday', 'Tuesday', 'Wednedsay', 'Thursday', 'Friday', 'Saturday'];
    return month_names[this.getDay()];
  }

  Drupal.adefCamps = {};

  Drupal.adefCamps.formatSchedule = function (container, zoomLevel, daysToShow, startDate) {
    sessions = $(container).children();
    scheduleParams = Drupal.adefCamps.getScheuleParams(sessions);

    var newRow = true;
    var currentDayCode = "";
    var dayCredit = 0;
    var extraRowPaddingForDate = 0;
    if (daysToShow > 1) {
      var headersToShow = daysToShow;
      extraRowPaddingForDate = 150;
      var dayHeader = $('<div></div>');
      $(dayHeader).css('width', extraRowPaddingForDate).addClass('day-header');
    }
    var fullWidth = $(container).width() - $(sessions).first().width();
    var zoomFactor = 2;
    if (zoomLevel == 1) {
      zoomFactor = fullWidth / (scheduleParams.dayLength * daysToShow);
    } else {
      var fullWidthWithHeader = (scheduleParams.dayLength * daysToShow * zoomFactor) + $(sessions).first().width() + (daysToShow * extraRowPaddingForDate);
      $(container).parent().outerWidth(fullWidthWithHeader);
    }

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
          if (daysToShow > 1) {
            if (headersToShow > 0) {
              var headerDate = new Date(dayCode);
              $(dayHeader).html(Drupal.t(headerDate.getWeekdayName()) + ' ' + headerDate.getDate() + ' ' + Drupal.t(headerDate.getMonthName()));
              $(dayHeader).clone().insertBefore(this);
              headersToShow -= 1;
            } else {
              dayRowShift += (extraRowPaddingForDate / zoomFactor);
            }

//            // find out if we need to skip days
//            var dayDate = new Date(dayCode);
//            var currentDate = (currentDayCode == "") ? startDate : new Date(currentDayCode);
//            var dateDiff = 0;
//            dateDiff = dayDate - currentDate
//            dateDiff = (dateDiff / (1000 * 60 * 60 * 24)) - 1;
//            dayRowShift += dateDiff * (scheduleParams.dayLength + (extraRowPaddingForDate / zoomFactor));
          }
          if (!newRow) { //same row
            dayRowShift += (scheduleParams.dayLength - dayCredit);
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

}(jQuery, Drupal));
