function checkDate(date) {
    if (typeof date !== "string" || date.trim() === "") {
        return false; 
    }
  
    const dateArray = date.split("-");
    if (dateArray.length !== 3) {
        return false; 
    }
  
    const [year, month, day] = dateArray;
  
    if (!/^\d+$/.test(year) || !/^\d+$/.test(month) || !/^\d+$/.test(day)) {
        return false; 
    }
  
    const yearNum = parseInt(year, 10);
    const monthNum = parseInt(month, 10);
    const dayNum = parseInt(day, 10);
  
    if (yearNum < 1) {
        return false;
    }
  
    if (monthNum < 1 || monthNum > 12) {
        return false;
    }
  
    const daysInMonth = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
  
    const isLeapYear = (yearNum % 4 === 0 && yearNum % 100 !== 0) || (yearNum % 400 === 0);
    if (isLeapYear) {
        daysInMonth[2] = 29;
    }
  
    if (dayNum < 1 || dayNum > daysInMonth[monthNum]) {
        return false;
    }
  
    return true; 
  }
  