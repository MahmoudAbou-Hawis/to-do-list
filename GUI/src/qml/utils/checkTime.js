function checkTime(time) {
    if (time === '') {
      return false;
    }
    const timeArray = time.split(':');
    if (timeArray.length !== 2) {
      return false;
    }
    if (timeArray[0].length !== 2 || timeArray[1].length !== 2) {
      return false;
    }
    if (timeArray[0] < 0 || timeArray[0] > 23) {
      return false;
    }
    if (timeArray[1] < 0 || timeArray[1] > 59) {
      return false;
    }
    return true;
  }