#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

void print_array(int * array, size_t array_size)
{
    std::cout << "Array with size " << array_size << std::endl;
    for (size_t i = 0; i < array_size; i++)
        std::cout << array[i] << " ";

    std::cout << std::endl;
}

void counting_sort(int* array, size_t size, size_t max_value)
{
    int * counting_array = new int(max_value+1);

    for (size_t i = 0; i < max_value+1; i++)
        counting_array[i] = 0;

    for (size_t i = 0; i < size; i++)
        counting_array[array[i]]++;

    int array_idx = 0;
    for (size_t i = 0; i < max_value+1; i++)
        while (counting_array[i] > 0)
        {
            array[array_idx] = i;
            array_idx++;
            --counting_array[i];
        }
}

int main()
{
    size_t array_size = 12; 
    int * array_to_sort1 = new int[array_size];
    int * array_to_sort_orig = new int[array_size];
    for (size_t i = 0; i < array_size; i++)
    {
        int rand_num = rand() % array_size;
        array_to_sort1[i] = rand_num;
        array_to_sort_orig[i] = rand_num;
    }
    print_array(array_to_sort1, array_size);

    std::cout << "counting sort:" << std:: endl;
    counting_sort(array_to_sort1, array_size, array_size);
    print_array(array_to_sort1, array_size);

    std::cout << "sorted array:" << std:: endl;
    std::sort(array_to_sort_orig, array_to_sort_orig+array_size);
    print_array(array_to_sort_orig, array_size);
}