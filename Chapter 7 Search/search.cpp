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

int binary_search(int * array, int size, int value)
{
    int min_idx = 0;
    int max_idx = size-1;
    int mid_idx = (min_idx+max_idx)/2;

    while(min_idx <= max_idx)
    {
        mid_idx = (min_idx+max_idx)/2;

        if (value > array[mid_idx])
        {
            min_idx = mid_idx+1;
        } else if (value < array[mid_idx]) {
            max_idx = mid_idx-1;
        } else {
            return mid_idx;
        }

    }
    return -1;
}

int main()
{
    int my_arr[5] = {1, 2, 3, 4, 5};

    cout << linear_search(my_arr, 5, 4) << endl;

    cout << linear_search(my_arr, 5, 4) << endl;
}