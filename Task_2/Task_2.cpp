// Task 2. This is the air temperature for each day of January.
// Define:
// a) average temperature for the month;
// 6) how many times the air temperature dropped below for the specified label.
//

#include <iostream>
using namespace std;

int main()
{
	int jan[31];
	int m_temp = 0;
	int bl_tmp_m = 0;
	int user_int_temp = 0;

	srand(time(NULL));

	/*========|| Array generating ||=========*/

	for (int i = 0; i < 31; i++)
	{
		int ran = rand() % 2 + 1; // chance of a negative temperature

		if (ran == 2)
		{
			int r = rand() % 15 + 0;
			r = -r;
			jan[i] = r;
		}
		else
		{
			jan[i] = rand() % 15 + 0;
		}
	}


	cout << "\n\n\tEnter the temperature what you interesting: ";	cin >> user_int_temp;
	cout << "\n\n\t";

	int k = 0;
	
	for (int i = 0; i < 5; i++)
	{
		for (int c = 0; c < 7; c++)
		{
			if (k < 31)
			{
				if (jan[k] <= user_int_temp)
				{
					bl_tmp_m++;	//temperature dropped below for the specified label.
				}
				m_temp += jan[k];

				cout << jan[k] << "\t";//Out calendar
				k++;//Days
			}
		}
		cout << "\n\t";
	}
	m_temp /= 31;//Average temperature

	cout << "\n\n\tMidl temperature in January is " << m_temp;
	cout << "\n\tThe temeratury was below a " << user_int_temp << " --> " << bl_tmp_m << " times\n\n\t";
}
