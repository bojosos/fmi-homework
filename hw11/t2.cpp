#include <iostream>

int main ()
{
	int time1, time2;
	std::cin >> time1 >> time2;
	
	int mins1 = time1 & 0x3f;
//	std::cout << mins1 << std::endl;
	
       	int tmp1 = time1 >> 0x6 & 0xf;
	//std::cout << hp1 << std::endl;

	int tmp2 = time1 >> 0xa & 0x3;
	//std::cout << hp2 << std::endl;
	int hours1 = tmp2 * 10 + tmp1;
//	std::cout << hours1 << std::endl;

	int format1 = time1 >> 0xc & 0x1;
	
	std::cout << format1 << std::endl;

	int mins2 = time2 & 0x3f;
	tmp1 = time2 >> 0x6 & 0xf;
	tmp2 = time2 >> 0xa & 0x3;
	int hours2 = tmp2 * 10 + tmp1;

	int format2 = time2 >> 0xc & 0x1;
	std::cout << format2 << std::endl;

	std::cout << hours1 << ":" << mins1 << std::endl << hours2 << ":" << mins2 << std::endl;

	int dif = std::abs(time1 - time2);
	int minsDif = dif & 0x3f;
	tmp1 = dif >> 0x6 & 0xf;
	tmp2 = dif >> 0xa & 0x3;
	int hoursDif = tmp2 * 10 + tmp1;
	std::cout << "diff " << hoursDif << ":" << minsDif << std::endl;


	return 0;
}
