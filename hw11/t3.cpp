#include <iostream>

int64_t timeToStamp(int day, int month, int year, int hours, int minutes, int seconds)
{
	// Day 1.1.0000 is day 0
	
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
//	std::cout << daysFromStart << std::endl;
	int remove = 0;
	if (year % 4 == 0) // Leap year check if we are before or after
	{
		if (month == 0 || (month == 1 && day <= 28))
		{
			remove = 1;
		}
	}
	//if (remove == 1)
	//	std::cout << "Here" << std::endl;
	//
	std::cout << ((((year * 365L + year / 4 - year / 100 + year / 400) + daysFromStart - remove + 1) * 24 + hours) * 60 + minutes) * 60 + seconds << std::endl;
	int64_t res = ((((year * 365L /* long? */ + year / 4 - year / 100 + year / 400) + daysFromStart - remove + 1) * 24 + hours) * 60 + minutes) * 60 + seconds;
	std::cout << day << "." << month << "." << year << " " << hours << ":" << minutes << ":" << seconds << "->" << res << std::endl;
	return res;
}

int decode(int64_t time)
{
	std::cout << time / 24 / 60 / 60 << std::endl;
	std::cout << (time / 60 / 60) % 24 << ":" << (time / 60) % 60 << ":" << time % 60 << std::endl;
	return 1;
}

int main ()
{
	// Samo da otbeleja che godina 0000 ne sushtestuva

	// Check if day in leap year is after or before 02.28
	// Add every 400 remove every 100 add every 4
	
	int day1, month1, year1, hours1, mins1, secs1;
	char tmp1;
	std::cin >> day1 >> tmp1 >> month1 >> tmp1 >> year1 >> hours1 >> tmp1 >> mins1 >> tmp1 >> secs1;

	int day, month, year, hours, mins, secs;
	char tmp;
	std::cin >> day >> tmp >> month >> tmp >> year >> hours >> tmp >> mins >> tmp >> secs;

//	std::cout << timeToStamp(day, month, year, hours, mins, secs) << std::endl;
//	std::cout << timeToStamp(day1, month1, year1, hours1, mins1, secs1) << std::endl;
//	std::cout << timeToStamp(day, month, year, hours, mins, secs) - timeToStamp(day1, month1, year1, hours1, mins1, secs1) << std::endl;

	std::cout << decode(std::abs(timeToStamp(day, month, year, hours, mins, secs) - timeToStamp(day1, month1, year1, hours1, mins1, secs1)));
/*
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int last = -1;
	int errors = 0;
	for (int year = 0; year < 101; year++)
	{
		for (int month  = 1; month <= 12; month++)
		{
			if (year % 4 == 0)
			{
				days[1] = 29;
			}
			else
				days[1] = 28;

			for (int day = 1; day <= days[month - 1]; day++)
			{
			//	std::cout << day << "." << month << "." << year << "->" << timeToStamp(day, month, year)  << std::endl;
				if (last + 1 != timeToStamp(day, month, year))
				{
					std::cout << "Error" << std::endl;
					errors += 1;
	//				return 0;
				}
				last = timeToStamp(day, month, year);
			}
		}
	}
	std::cout << errors << std::endl;
*/
	return 0;
}
