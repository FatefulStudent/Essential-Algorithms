#include <stdlib.h>
#include <iostream>
#include <algorithm>

int find_min_index(int * start_ptr, int * end_ptr)
{
    int min_index = 0;
    int index_counter = 1;
    int min_element = *start_ptr;

    for (int * i = start_ptr+1; i != end_ptr; i++, index_counter++)
    {
        if (min_element > *i)
        {
            min_element = *i;
            min_index = index_counter;
        }
    }

    return min_index;
}

void insertion_sort(int* array, size_t size)
{
    int min_index = 0;

    for (size_t i = 0; i < size; i++)
    {
        min_index = find_min_index(array + i, array + size);
        // std:: cout << "element #" << i << std::endl;
        // std:: cout << "min_index at " << i+min_index << std::endl;
        if (min_index)
        {
            for (size_t j = i + min_index; j > i; j--)
            {
                // std:: cout << "exchanging indexes " << j << ", " << j-1 << std::endl;
                std::swap(array[j-1], array[j]);
            }
            
        }
    }
}


void print_array(int * array, size_t array_size)
{
    std::cout << "Array with size " << array_size << std::endl;
    for (size_t i = 0; i < array_size; i++)
        std::cout << array[i] << " ";

    std::cout << std::endl;
}

int main()
{
    size_t array_size = 10; 
    int * array_to_sort1 = new int[array_size];
    int * array_to_sort_orig = new int[array_size];
    for (size_t i = 0; i < array_size; i++)
    {
        int rand_num = rand() % array_size;
        array_to_sort1[i] = rand_num;
        array_to_sort_orig[i] = rand_num;
    }
    print_array(array_to_sort1, array_size);
    insertion_sort(array_to_sort1, array_size);
    print_array(array_to_sort1, array_size);

    std::sort(array_to_sort_orig, array_to_sort_orig+array_size);
    print_array(array_to_sort_orig, array_size);

    // std::cout << *find_min_element(array_to_sort + 3, 
    //                                array_to_sort + array_size);

}