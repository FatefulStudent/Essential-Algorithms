#include <iostream>

using std::cout;
using std::endl;

int linear_search(int * array, int size, int value)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

int main()
{
    int my_arr[5] = {3,4,1,4,5};

    cout << linear_search(my_arr, 5, 1);
}