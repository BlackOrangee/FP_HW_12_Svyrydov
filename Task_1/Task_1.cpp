// Task 1.The array stores information on the number of residents of each apartment in a five-story building (4 entrances, 2 apartments on each floor).
// a) determine the number of residentsand their neighbors living on the same floor by the selected apartment number;
// 6) determine the total number of residents for each entrance;
// c) determine apartment numbers where large families live. Conventionally, we will consider families with more than five children to be large families.
//

#include <iostream>
using namespace std;

int main()
{
	int house[5][8];
	int menu = 0;
	int ap_num = 0;
	int en_num = 0;
	int nbap_num = 0;
	int k = 0;
	int residents = 0;
	int neighbors = 0;
	int a = 0, b = 2;
	int another = 0;


	for (int i = 0; i < 5; i++)
	{
		for (int c = 0; c < 8; c++)
		{
			house[i][c] = rand() % 7 + 0;
		}
	}
	
	while (true)
	{
		system("cls");

		cout << "\n\tEntrance\t1\t2\t3\t4\n\n\t";

		for (int i = 4; i >= 0; i--)
		{
			int n = i + 1;

			cout << "Floor " << n << "\t\t";
			for (int c = 0; c < 8; c++)
			{
				cout << house[i][c] << " ";

				if (c % 2)
				{
					cout << "\t";
				}
			}
			cout << "\n\t";
		}
		cout << "\n\t1 -- Determine the number of residents and their neighbors living on the same floor by the selected apartment number;";
		cout << "\n\t2 -- Determine the total number of residents for each entrance;";
		cout << "\n\t3 -- Determine apartment numbers where large families live.\n\t";	cin >> menu;

		switch (menu)
		{
		case 1:
			cout << "\n\tEnter the apartment number\n\t"; cin >> ap_num;

			a = 0;
			b = 2;
			k = 0;

			for (int f = 0; f < 4; f++)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int c = a; c < b; c++)
					{
						k++;
						if (k == ap_num)
						{
							residents = house[i][c];
							
							if (c % 2)
							{
								neighbors = house[i][c - 1];
								nbap_num = ap_num - 1;
							}
							else
							{
								neighbors = house[i][c + 1];
								nbap_num = ap_num + 1;
							}
						}
					}
				}
				a += 2;
				b += 2;
			}
			cout << "\n\n\tResidents in apartment number " << ap_num << " is " << residents << " persons";
			cout << "\n\tTheir neighbors from apartment number " << nbap_num << " is " << neighbors << " persons";
			cout << "\n\tTotal persons in the floor: " << residents + neighbors << " persons";
			cout << "\n\n\t0 -- Another option\n\t";	cin >> another;

			break;
		case 2:

			a = 0;
			b = 2;
			k = 1;

			for (int f = 0; f < 4; f++)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int c = a; c < b; c++)
					{
						residents += house[i][c];
					}
				}
				cout << "\n\tResidents in entrance " << k << " is " << residents << " persons";
				a += 2;
				b += 2;
				k++;
			}
			cout << "\n\n\t0 -- Another option\n\t";	cin >> another;
			break;
		case 3:
			cout << "\n\tLarge families live apartments number: ";
			a = 0;
			b = 2;
			k = 0;

			for (int f = 0; f < 4; f++)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int c = a; c < b; c++)
					{
						k++;
						if (house[i][c] > 5)
						{
							cout << k << " ";
						}
					}
				}
				a += 2;
				b += 2;
			}
			cout << "\n\n\t0 -- Another option\n\t";	cin >> another;

			break;
		default:
			break;
		}
	}
	
}
