// Task 3.
// Write a program that finds values that are repeated two or more times in an array and outputs them to screen.

#include <iostream>
using namespace std;

int main()
{
	const int size = 10;
	int arr[size];

	int rep_val[size];
	int rep_val_num = -1;

	int rep_val_sorted[size];
	int rep_val_sorted_mun = 0;

	srand(time(NULL));

	for (int i = 0; i < 31; i++)
	{
		arr[i] = rand() % 10 + 1;
		
	}
	cout << "\n\n\tGenerated array: ";

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		

	}

	int k = 1;
	for (int i = 0; i < size; i++)
	{
		rep_val_num = 0;
		if (arr[i] != -500)
		{


			for (int c = k; c < size; c++)
			{
				if ((arr[i] == arr[c]) && (arr[i] != -500))
				{
					rep_val_num++;
					arr[c] = -500;
				}
			}
		}
		if (arr[i] != -500)
		{
			cout << "\n\tThe numbet " << arr[i] << " was repeated " << rep_val_num << " times";
		}
		k++;

	}
}