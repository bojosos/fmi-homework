#include <iostream>

int64_t DateToTimestamp(int day, int month, int year, int hour, int minute, int second)
{
  month -= 1;
  day -= 1;
  int daysFromStart = day;
  
  switch(month)
  {
    case 11: daysFromStart += 30;
    case 10: daysFromStart += 31;
    case 9: daysFromStart += 30;
    case 8: daysFromStart += 31;
    case 7: daysFromStart += 31;
    case 6: daysFromStart += 30;
    case 5: daysFromStart += 31;
    case 4: daysFromStart += 30;
    case 3: daysFromStart += 31;
    case 2: daysFromStart += 28;
    case 1: daysFromStart += 31;
  }

  int remove = 0;
  if (year % 4 == 0)
  {
    if (month == 0 || (month == 1 && day <= 28))
    {
      remove = 1;
    }
  }
  
  int64_t days = (year * 365L /* long? */ + year / 4 - year / 100 + year / 400) + daysFromStart - remove + 1;
  int64_t res = ((days * 24 + hour) * 60 + minute) * 60 + second;
  
  return res;
}

bool ValidateDate(int day, int month, int year, int hour, int minute, int second)
{
  if (year < 0 || year > 9999)
    return false;
  if (month < 1 || month > 12)
    return false;
  int daysInMonth = 0;
  if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
  {
    daysInMonth = 29;
  }
  else
    switch(month)
    {
      case 1: daysInMonth = 31; break;
      case 2: daysInMonth = 28; break;
      case 3: daysInMonth = 31; break;
      case 4: daysInMonth = 30; break;
      case 5: daysInMonth = 31; break;
      case 6: daysInMonth = 30; break;
      case 7: daysInMonth = 31; break;
      case 8: daysInMonth = 31; break;
      case 9: daysInMonth = 30; break;
      case 10: daysInMonth = 31; break;
      case 11: daysInMonth = 30; break;
      case 12: daysInMonth = 31; break;
    }
  
  if (day < 0 || day > daysInMonth)
    return false;
  if (hour < 0 || hour > 24 || minute < 0 || minute > 59 || second < 0 || second > 59)
    return false;
  return true;
}

void PrintFormattedTime(int64_t time)
{
  uint32_t days = time / 24 / 60 / 60;
  if (days != 0)
    std::cout << days << "-";

  int hh = (time / 60 / 60) % 24;
  int mm = (time / 60) % 60;
  int ss = (time % 60);

  if (hh < 10)
    std::cout << 0;
  std::cout << hh << ":";
  if (mm < 10)
    std::cout << 0;
  std::cout << mm << ":";
  if (ss < 10)
    std::cout << 0;
  std::cout << ss << std::endl;
}

int main ()
{
  int day1, month1, year1, hour1, min1, sec1;
  char tmp;
  std::cin >> day1 >> tmp >> month1 >> tmp >> year1 >> hour1 >> tmp >> min1 >> tmp >> sec1;
  
  if (!ValidateDate(day1, month1, year1, hour1, min1, sec1))
  {
    std::cout << "Invalid date/time" << std::endl;
    return 0;
  }

  int day2, month2, year2, hour2, min2, sec2;
  std::cin >> day2 >> tmp >> month2 >> tmp >> year2 >> hour2 >> tmp >> min2 >> tmp >> sec2;

  if (!ValidateDate(day2, month2, year2, hour2, min2, sec2))
  {
    std::cout << "Invalid date/time" << std::endl;
    return 0;
  }

  int64_t dif = std::labs(DateToTimestamp(day1, month1, year1, hour1, min1, sec1) - DateToTimestamp(day2, month2, year2, hour2, min2, sec2));
  PrintFormattedTime(dif);

  return 0;
}
