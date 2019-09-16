#include <stdlib.h>
#include <iostream>
#include <algorithm>


void print_array(int * array, size_t array_size)
{
    std::cout << "Array with size " << array_size << std::endl;
    for (size_t i = 0; i < array_size; i++)
        std::cout << array[i] << " ";

    std::cout << std::endl;
}

int find_min_index(int * start_ptr, int * end_ptr, bool first_min)
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
            if (first_min)
                break;
        }
    }

    return min_index;
}

void insertion_sort(int* array, size_t size)
{
    int min_index = 0;
    int insert_index = 0;

    for (size_t i = 0; i < size; i++)
    {
        min_index = find_min_index(array + i, array + size, true);
        if (min_index)
        {
            
            // finding appropriate place
            insert_index = 0;
            while (array[i+min_index] > array[insert_index])
                insert_index++;

            // swapping the elements
            for (size_t j = i + min_index; j > insert_index; j--)
                std::swap(array[j-1], array[j]);
        }
    }
}

void selection_sort(int* array, size_t size)
{
    int min_index = 0;

    for (size_t i = 0; i < size; i++)
    {
        min_index = find_min_index(array + i, array + size, false);
        if (min_index)
        {
            std::swap(array[i], array[i+min_index]);// swapping the elements
        }
    }
}

void bubble_sort(int* array, size_t size)
{
    bool is_sorted = false;
    while (!is_sorted)
    {
        is_sorted = true;
        for (size_t i = 0; i < size-1; i++)
        {
            if (array[i] > array[i+1])
            {
                is_sorted = false;
                std::swap(array[i], array[i+1]);
            }
        }
    }
    
        
}

int main()
{
    size_t array_size = 17; 
    int * array_to_sort1 = new int[array_size];
    int * array_to_sort_orig = new int[array_size];
    for (size_t i = 0; i < array_size; i++)
    {
        int rand_num = rand() % array_size;
        array_to_sort1[i] = rand_num;
        array_to_sort_orig[i] = rand_num;
    }
    print_array(array_to_sort1, array_size);
    bubble_sort(array_to_sort1, array_size);
    print_array(array_to_sort1, array_size);

    std::sort(array_to_sort_orig, array_to_sort_orig+array_size);
    print_array(array_to_sort_orig, array_size);


}