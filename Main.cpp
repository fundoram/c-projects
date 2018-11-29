/*Matthew Fundora 
  Tony Biehl
  Data Structures
  09/13/18

*/

#include "Lab1.h"



int main() {




	int n;
	int ch;


	do
	{


		// prints to user
		cout << "1. Recursive factorial" << endl;
		cout << "2. Tower of Hanoi" << endl;
		cout << "3. Recursive Summation" << endl;
		cout << "0. Exit" << endl;

		cout << endl << "Enter choice: ";
		//recieeves user input
		cin >> ch;
		// forces user to enter a numeric number
		if (!cin) {
			cout << "Invalid input\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (ch == 0) {
			cout << endl << endl << "You chose to exit\n";
			system("pause");
			exit(0);
		}
		else if (ch == 1) {

			cout << endl << "Enter a number to find factorial: ";
			cin >> n;

			//calling long fact in header 
			long fact = factorial(n);

			cout << endl << "Factorial of " << n << " is: " << fact << endl << endl;
			system("pause");
		}
		else if (ch == 2) {
			// sets up for user input

			cout << "Enter number of disks: ";
			cin >> n;
			toH(n, 'A', 'B', 'C');
			cout << endl << endl;
			system("pause");
		}

		else if (ch == 3) {
			// sets up for user input


			cout << endl << "Please enter a number to find Recursive summation: ";
			cin >> n;
			//calling sum in header
			int sum = summation(n);
			system("pause");
			cout << endl << "Sum is: " << sum << endl << endl;


		}

	} while (ch != 0);









}