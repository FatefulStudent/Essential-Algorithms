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

// from an unsorted array to a heap
void make_heap(int * array, size_t size)
{
    int parent_index = 0;
    int index = 0;
    for (size_t i = 0; i < size; i++)
    {
        index = i;

        while(index)
        {
            // делаем просев для восстановления свойства кучи
            parent_index = (index - 1)/2;    

            // if we find its place we stop
            if (array[index] <= array[parent_index])
                break;
            
            std::swap(array[index], array[parent_index]);
            index = parent_index;
        }
    }
}

// removing maximum element from heap and 
// restoring its quality
int remove_top_heap(int* array, int size)
{
    int result = array[0];

    array[0] = array[size-1];
    int index = 0;
    while (true)
    {
        int child1_index = index*2 + 1;
        int child2_index = index*2 + 2;

        // bound indexes to array
        if (child1_index >= size)
            child1_index = index;
        
        if (child2_index >= size)
            child2_index = index;

        // checking the main property of the heap
        if (array[index] >= array[child1_index] && 
        array[index] >= array[child2_index])
            break;

        int swap_index = array[child1_index] > array[child2_index] 
                         ? child1_index : child2_index;

        std::swap(array[swap_index], array[index]);
        index = swap_index;
    }
    return result;
}

// making a heap then iteratively removing max elements
// and putting it ot the right of array
void heap_sort(int* array, size_t size)
{
    int max_element = 0;
    // turning array into a heap
    make_heap(array, size);

    // removing max element and pushing it to the right
    int right_shift=0;
    for (int i = size - 1; i >= 0; i--, right_shift++)
    {
        max_element = remove_top_heap(array, size-right_shift);
        array[i] = max_element;
    }
}

void quick_sort(int* array, size_t size)
{
    if (size == 0 || size == 1)
        return;
    int middle_index = rand() % size;
    int middle = array[middle_index];

    std::vector<int> lesser_elements;
    std::vector<int> bigger_elements;
    
    for (size_t i = 0; i < size; i++)
    {
        if (i == middle_index)
            continue;

        if (array[i] > middle)
            bigger_elements.push_back(array[i]);
        else
            lesser_elements.push_back(array[i]);
    }

    size_t array_index = 0;
    for (size_t j = 0; j < lesser_elements.size(); j++, array_index++)
    {
        array[array_index] = lesser_elements[j];
    }
        
    
    array[array_index] = middle;
    middle_index = array_index;
    array_index += 1;

    for (size_t j = 0; j < bigger_elements.size(); j++, array_index++)
    {
        array[array_index] = bigger_elements[j];
    }
        
    quick_sort(array, middle_index);
    quick_sort(array+middle_index, size-middle_index);
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

    std::cout << "quick sort:" << std:: endl;
    quick_sort(array_to_sort1, array_size);
    print_array(array_to_sort1, array_size);

    std::cout << "sorted array:" << std:: endl;
    std::sort(array_to_sort_orig, array_to_sort_orig+array_size);
    print_array(array_to_sort_orig, array_size);
}