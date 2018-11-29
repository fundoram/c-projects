#include <iostream>
#include "Lab1.h"

// hers is basically where the math happens 





void start(void)
{

}

long factorial(int number) {
	if (number >= 1)

		return number * factorial(number - 1);
	else
		return 1;
}

void toH(int n, char start, char a, char dest) {
	if (n == 1) {
		cout << "Move Disk " << n << " from " << start << " to " << dest << endl;
		return;
	}

	toH(n - 1, start, dest, a);
	cout << "Move Disk " << n << "  " << start << " to " << dest << endl;
	toH(n - 1, a, start, dest);
}

int summation(int number) {
	if (number != 0)
		return number + summation(number - 1);
	else
		return number;
}
