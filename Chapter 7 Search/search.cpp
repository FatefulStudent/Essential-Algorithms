#include <iostream>

using std::cout;
using std::endl;

int linear_search(int * array, int size, int target)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == target)
            return i;
    }
    return -1;
}

int binary_search(int * array, int size, int target)
{
    int min_idx = 0;
    int max_idx = size-1;
    int mid_idx = (min_idx+max_idx)/2;

    while(min_idx <= max_idx)
    {
        mid_idx = (min_idx+max_idx)/2;

        if (target > array[mid_idx])
        {
            min_idx = mid_idx+1;
        } else if (target < array[mid_idx]) {
            max_idx = mid_idx-1;
        } else {
            return mid_idx;
        }

    }
    return -1;
}

int binary_search_recursive(int * array, int size, int target)
{
    int min_idx = 0;
    int max_idx = size-1;
    int mid_idx = (min_idx+max_idx)/2;

    if (array[0] == target)
        return 0;
    if (min_idx > max_idx)
        return -1;

    if (target > array[mid_idx])
    {
        min_idx = mid_idx+1;
        return mid_idx+1+binary_search_recursive(array+min_idx, size-min_idx, target);
    } else if (target < array[mid_idx]) {
        max_idx = mid_idx-1;
        return binary_search_recursive(array, max_idx, target);
    } else {
        return mid_idx;
    }

    return -1;
}

int interpolation_search(int * array, int size, int target)
{
    int min_idx = 0;
    int max_idx = size-1;
    int mid_idx = 0;

    while(min_idx <= max_idx)
    {
        mid_idx = min_idx + (target - array[min_idx])/(array[max_idx] - array[min_idx]) * (max_idx - min_idx);

        if (target > array[mid_idx])
        {
            min_idx = mid_idx+1;
        } else if (target < array[mid_idx]) {
            max_idx = mid_idx-1;
        } else {
            return mid_idx;
        }

    }
    return -1;
}

int main()
{
    int size = 11;
    int target = 1;
    int my_arr[11] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 12, 13};

    cout << linear_search(my_arr, size, target) << endl;

    cout << binary_search_recursive(my_arr, size, target) << endl;
}