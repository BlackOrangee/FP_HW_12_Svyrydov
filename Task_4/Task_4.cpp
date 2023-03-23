// Task 4. Fill two integer arrays A[10] and B[10]. Form the third array X[20], the elements of which will be taken from A and B are in order :
// a) alternation(A0, b0, a1, b1, a2, b2, ..., a9, b9);
// 6) following(A0, a1, a2, ..., A9, 60, 61, 62, ..., b9).
//

#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
    int a_arr[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int b_arr[size] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    int x_arr[20];
    int x_arr_B[20];
    
    for (int i = 0, i_ = 0, k = 0; i < size; i++)
    {/*=======|| a) Alternation ||=========*/
        x_arr[k] = a_arr[i];    
        k++; 
        x_arr[k] = b_arr[i];
        k++;
             
     /*=======|| 6) Following ||=========*/
        x_arr_B[i] = a_arr[i];
        i_ = i + 10;
        x_arr_B[i_] = b_arr[i];

    }
    
    /*========|| Data out ||=========*/
    
    
    /*Basic array "A"*/

    cout << "\n\n\tArray A: ";

    for (int i = 0; i < size; i++)
    {
        cout << a_arr[i] << " ";
    }

    /*Basic array "B"*/

    cout << "\n\n\tArray B: ";

    for (int i = 0; i < size; i++)
    {
        cout << b_arr[i] << " ";
    }


    /*========|| Program result ||=========*/

    cout << "\n\n\tArray X, variant a: ";
    for (int i = 0; i < size * 4; i++)
    {
        if (i < (size*2))
        {
            cout << x_arr[i] << " ";

        }
        else if (i == (size*2))
        {
            cout << "\n\n\tArray X, variant b: ";
        }
        if (i >= (size*2))
        {
            int i_ = i - 20;
            cout << x_arr_B[i_] << " ";
        }
       
       
    }
    cout << "\n\n\n";
}