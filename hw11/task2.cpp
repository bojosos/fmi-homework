#include <iostream>

bool Validate(int format, int hours, int mins)
{
  if (format == 0 && hours > 12)
  {
    std::cout << "Hours cannot be over 12 when using 12 hour time format!" << std::endl;
    return false;
  }

  if (hours > 24)
  {
    std::cout << "Hours cannot be over 24 when using 24 hour time format!" << std::endl;
    return false;
  }
  
  if (mins > 59)
  {
    std::cout << "Minutes cannot be over 59!" << std::endl;
    return false;
  }
  
  return true;
}

int main ()
{
  int time1, time2;
  std::cin >> time1;
  
  if (time1 < 0 || time1 >= 6400)
  {
    std::cout << "The decimal time value has to be in the range [0, 6400)!" << std::endl;
    return 0;
  }
  
  int mins1 = time1 & 0x3f;
  int tmp1 = time1 >> 0x6 & 0xf;
  int tmp2 = time1 >> 0xa & 0x3;

  int hours1 = tmp2 * 10 + tmp1;
  int format1 = time1 >> 0xc;

  if (hours1 < 10)
    std::cout << 0;
  std::cout << hours1 << ":" ;
  if (mins1 < 10)
    std:: cout << 0;
  std::cout << mins1 << std::endl;
  if (!Validate(format1, hours1, mins1))
    return 0;


  std::cin >> time2;
  if (time1 < 0 || time1 >= 6400)
  {
    std::cout << "The decimal time value has to be in the range [0, 6400)!" << std::endl;
    return 0;
  }

  int mins2 = time2 & 0x3f;
  tmp1 = time2 >> 0x6 & 0xf;
  tmp2 = time2 >> 0xa & 0x3;

  int hours2 = tmp2 * 10 + tmp1;
  int format2 = time2 >> 0xc;

  if (!Validate(format2, hours2, mins2))
    return 0;
  
  if (hours2 < 10)
    std::cout << 0;
  std::cout << hours2 << ":";
  if (mins2 < 10)
    std::cout << 0; 
  std::cout << mins2 << std::endl;

  int dif = std::abs(hours1 * 60 + mins1 - hours2 * 60 - mins2);
  int minsDif = dif % 60;
  int hoursDif = dif / 60;

  std::cout << "diff " << hoursDif << ":";
  
  if (minsDif < 10)
    std::cout << 0;
  std::cout << minsDif << std::endl;


  return 0;
}
