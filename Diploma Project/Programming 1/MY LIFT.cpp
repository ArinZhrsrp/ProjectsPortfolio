#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void first();
void button();

void cinWeight()
{
		int bodyweight, again, sum = 0;

		int count = 1;
		while (count == count)

		{

			cout << "Enter the person weight in kg: ";
			cin >> bodyweight;
			if(bodyweight>500)
			{
					int e;
		
					cout << "\nAre There Any Emergency? \n1.Yes \n2.No" << "\n" << endl;
					cin >> e;
	
					if(e == 1)
					{
						system("CLS");
						cout << "The Elevator Is Going Down\n" << endl;
						system("pause");
						system ("CLS"); 
						cout << "NOT IN SERVICE\n" << endl;
						button();
						exit(0);
					}
					else if (e == 2)
					{
						system("CLS");
						cout << "The Elevator Has Exceed Its Weight Limit" << endl;
						exit(0);
					}
			}
			else if(bodyweight>=0&&bodyweight<=500)
			{
				cout << "\nAny other person? \n 1-Yes \n 2-No" << endl;
			cin >> again;
			cout << endl;
			if (again == 1)
			{
				count = count + 1;
				sum = sum + bodyweight;
			}

			else if (again == 2)
			{
				sum = sum + bodyweight;
				cout << "THE SUM IS: " << sum << endl << endl;
				cout << "------------------------------------------------------------------------------------------------------" << endl;
				
				if(sum>500)
				{
					int e;
		
					cout << "\nAre There Any Emergency? \n1.Yes \n2.No" << "\n" << endl;
					cin >> e;
	
					if(e == 1)
					{
						system("CLS");
						cout << "The Elevator Is Going Down\n" << endl;
						system("pause");
						system ("CLS"); 
						cout << "NOT IN SERVICE\n" << endl;
						button();
						exit(0);
					}
					else if (e == 2)
					{
						system("CLS");
						cout << "The Elevator Has Exceed Its Weight Limit" << endl;
						exit(0);
					}
				}
				else
				{
					break;
				}
		
			}
			}else if(bodyweight<0)
			{
				cout<<"Please re-open and retry";
				exit(0);
			}
			

		}

		cout << "\n THE TOTAL WEIGHT IN ELEVATOR IS: " << sum << endl;

	}

int main ()
{
	
	string num;
	first();
	getline(cin, num);
	system("CLS");
	// clear screen

	cinWeight();
	
	
	int a = 0, f, c = 1, x;	
	
	do
	{
		cout << "\nDestination level : ";
		cin >> f;
		cout << "\n";
		
		if(f>0&&f<11)
		{
				while (a < f && f < 11)
		{
			a = a + 1;
			cout << "Floor" << a << endl;
			
		}
		}
		else
		{
			cout<<"Please re-open and retry.";
			exit(0);
		}
	
	}
	while (a > f || f > 11);
	
	for (x = 0;x < 5;x++)
	{
		cout << "\nYou have arrived.See you again.\nAgain?\n1.Yes\n2.No\n";
		cin >> c;
		
		if(c == 2)
		break;
		if(c == 1)
		{
			cinWeight();
			cout << "\nDestination level : ";
			cin >> f;
			cout << "\n";
			if(f>=1&&f<=10)
			{
				if(a < f)
			{
				cout << "You are moving up" << endl;
				while (a < f)
				{
					a = a + 1;
					cout << "Floor " << a << endl;
				}
			}
			else if (a > f)
			{
				cout << "You are moving down" << endl;
				while (a > f)
				{
					a = a - 1;
					cout << "Floor " << a << endl;
				}
			}

			}
			else
		{
			cout<<"Please reopen and retry.";
			exit(0);
		}
		}
	}
	
	cout << "Thank You For Using Our Service";
	return 0;
}

void first()

{
	cout << " Elevator weight limit is 500kg. \n";
	cout << " Enter any key to proceed.\n ";
}

void button()
{
	//NUMBER FOR EMERGENCY BUTTON IS EQUAL TO ZERO.
	bool done = false;
	string FLOOR;
	do
	{
		cout << "PRESS BUTTON A FOR EMERGENCY NUMBER" << endl;
		cin >> FLOOR;

		if (FLOOR == "A" || FLOOR == "a")
		{
			cout << "\nTHIS IS A EMERGENCY NUMBER THAT WILL HELP YOU." << endl;
			cout << setw(30) << "CONTACT NUMBER : 9  9  9 " << endl;

			done = true;
			break;
		}
		else
		{
			cout << "PRESS AGAIN THE BUTTON" << endl;
			continue;

		}
	} while (!done);

}
