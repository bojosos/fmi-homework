#include <iostream>
using namespace std;
int main ()
{
	int number = 32;
	int counter = 0, currentNumber = 1;
	while (number >= currentNumber)
	{
		currentNumber *= 3;
		counter++;
	}

	std::cout << counter << std::endl;

	return 0;
}
