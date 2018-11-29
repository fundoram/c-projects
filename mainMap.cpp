

#include <iostream>
#include <string>
#include "map.h"

using namespace std;

int main()
{
	Map HPAir;

	HPAir.readMap("cities.txt", "flights.txt");
	HPAir.flights("requestFile.txt");

	system("pause");
	return 0;
}