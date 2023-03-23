// Task 3.
// Write a program that finds values that are repeated two or more times in an array and outputs them to screen.

#include <iostream>
using namespace std;

int main()
{
	const int size = 10;
	int arr[size];
	int rep_val_num = -0;

	srand(time(NULL));

	/*========|| Array generating ||=========*/

	cout << "\n\n\tGenerated array: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10 + 1;
		cout << arr[i] << " ";
		
	}
	
	/*========|| Calculating ||=========*/
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		
		for (int c = 0; c < i; c++)
		{
			if (arr[i] == arr[c])
			{
				rep_val_num++;	//repeats mutch

				if (rep_val_num >= 2)// data out
				{
					cout << "\n\tThe numbet " << arr[i] << " was repeated " << rep_val_num + 1 << " times";
				}
			}
		}
		rep_val_num = 0;
	}
	


}