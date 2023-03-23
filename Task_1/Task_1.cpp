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
	int house_ap_num[5][8];
	int menu = 0;
	int ap_num = 0;
	int en_num = 0;
	int nbap_num = 0;
	int k = 0;
	int residents = 0;
	int neighbors = 0;
	int a = 0, b = 2;
	int another = 0;

	/*========|| Array generating ||=========*/
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
	/*
	  ===============|| Painting  table ||===================
	
		Entrance        1       2       3       4

        Floor 5         1 2     0 4     5 0     4 3
        Floor 4         5 6     5 5     6 1     1 5
        Floor 3         6 0     4 4     2 2     3 6
        Floor 2         5 6     0 5     6 6     0 1
        Floor 1         6 1     6 5     3 2     5 0
	
	*/
		/*  Entrance        1       2         3        4

			Floor 5         9 10    19 20     29 30    39 40
			Floor 4         7 8     17 18     27 28    37 38
			Floor 3         5 6     15 16     25 26    35 36
			Floor 2         3 4     13 14     23 24    33 34
			Floor 1         1 2     11 12     21 22    31 32
			*/
		cout << "\n\tEntrance\t1\t2\t3\t4\n\n\t";

		for (int i = 4; i >= 0; i--)
		{
			int n = i + 1;

			cout << "Floor " << n << "\t\t";
			for (int c = 0; c < 8; c++)
			{
				cout << house_ap_num[i][c] << " ";
				
				if (c % 2)
				{
					cout << "\t";
				}
			}
			cout << "\n\t";
		}

		/*===============|| Menu Options ||===================*/

		cout << "\n\t1 -- Determine the number of residents and their neighbors living on the same floor by the selected apartment number;";
		cout << "\n\t2 -- Determine the total number of residents for each entrance;";
		cout << "\n\t3 -- Determine apartment numbers where large families live.\n\t";	cin >> menu;

		switch (menu)
		{
		case 1:	/*===============|| Determine the number of residents and their neighbors ||===================*/

			cout << "\n\tEnter the apartment number\n\t"; cin >> ap_num;

			a = 0;
			b = 2;
			k = 0;

			for (int f = 0; f < 4; f++)	// Entrance
			{
				for (int i = 0; i < 5; i++)	// Floor 
				{
					for (int c = a; c < b; c++)
					{
						k++;
						if (k == ap_num) //apartment number
						{
							residents = house[i][c];	// Residents in curent apartments
							
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
			
			/*===============|| response to the request ||===================*/

			cout << "\n\n\tResidents in apartment number " << ap_num << " is " << residents << " persons";
			cout << "\n\tTheir neighbors from apartment number " << nbap_num << " is " << neighbors << " persons";
			cout << "\n\tTotal persons in the floor: " << residents + neighbors << " persons";
			cout << "\n\n\t0 -- Another option\n\t";	cin >> another;

			break;
		case 2:
			/*===============|| Determine the total number of residents for each entrance ||===================*/


			a = 0;
			b = 2;
			k = 1;

			for (int f = 0; f < 4; f++)// Entrance
			{
				for (int i = 0; i < 5; i++)// Floor 
				{
					for (int c = a; c < b; c++)// Residents
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
			/*===============|| Determine apartment numbers where large families live ||===================*/

			cout << "\n\tLarge families live apartments number: ";
			a = 0;
			b = 2;
			k = 0;

			for (int f = 0; f < 4; f++)// Entrance
			{
				for (int i = 0; i < 5; i++)// Floor 
				{
					for (int c = a; c < b; c++)
					{
						k++;
						if (house[i][c] > 5) //Searching large families apartments number
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
