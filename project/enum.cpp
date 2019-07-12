#include <iostream>
using namespace std;
// Declare the enumerated type
enum Roster { Tom = 1, Sharon, Bill, Teresa, John };
// Sharon - John will be assigned default values 2-5.
int main()
{
	int who;
	cin >> who;
	switch (who)
	{
	case Tom:
		cout << "Tom's birthday is January 3.\n";
		break;
	case Sharon:
		cout << "Sharon's birthday is April 22.\n";
		break;
	case Bill:
		cout << "Bill's birthday is December 19.\n";
		break;
	case Teresa:
		cout << "Teresa's birthday is February 2.\n";
		break;
	case John:
		cout << "John's birthday is June 17.\n";
		break;
	default:
		cout << "Invalid selection\n";
	}
	return 0;
}