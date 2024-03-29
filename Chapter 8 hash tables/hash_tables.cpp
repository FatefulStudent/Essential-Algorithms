#include <iostream>
#include <vector>

using std::vector;

static int HASH_SIZE = 10;

int hash(int num)
{
    return num % HASH_SIZE;
}

// Прямое связывание
struct SeparateChaining
{
    SeparateChaining()
    {
        array = vector<vector<int>>(HASH_SIZE);

        for (size_t i = 0; i < HASH_SIZE; i++)
        {
            array[i].push_back(i);
        }
    }

    void print()
    {
        for (size_t i = 0; i < HASH_SIZE; i++)
        {
            std::cout << "[";
            for (size_t j = 0; j < array[i].size(); j++)
            {
                std::cout << array[i][j] << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }

    void append(int num)
    {
        int block_num = hash(num);
        array[block_num].push_back(num);
    }

    bool find(int num)
    {
        int block_num = hash(num);
        for (size_t j = 0; j < array[block_num].size(); j++)
            if (array[block_num][j] == num)
                return true;

        return false;
    }

    vector<vector<int>> array;
};

// Открытая адресация с линейным пробированием
struct LinearOpenAddressing
{
    LinearOpenAddressing()
    {
        array = vector<int>(HASH_SIZE);

        for (size_t i = 0; i < HASH_SIZE; i++)
        {
            array[i] = -1;
        }
    }

    void print()
    {
        for (size_t i = 0; i < HASH_SIZE; i++)
        {
            std::cout << array[i] << ", ";
        }
        std::cout << std::endl;
    }

    bool block_is_free(int block_num)
    {
        return array[block_num] == -1;
    }

    void append(int num)
    {
        int block_num = hash(num);
        while (block_num < HASH_SIZE && !block_is_free(block_num))
        {
            block_num += 1;
        }
        
        if (block_num < HASH_SIZE)
            array[block_num] = num;
        else // should do resize
            std::cout << "HASH TABLE IS FULL!" << std::endl;
            
    }

    bool find(int num)
    {
        int block_num = hash(num);
        while (block_num < HASH_SIZE && !block_is_free(block_num))
        {
            block_num += 1;
            if (array[block_num] == num)
                return true;
        }
        return false;
    }

    vector<int> array;
};

// Открытая адресация с линейным пробированием
struct QuadraticOpenAddressing
{
    QuadraticOpenAddressing()
    {
        array = vector<int>(3*HASH_SIZE);

        for (size_t i = 0; i < 3*HASH_SIZE; i++)
        {
            array[i] = -1;
        }
    }

    void print()
    {
        for (size_t i = 0; i < 3*HASH_SIZE; i++)
        {
            std::cout << array[i] << ", ";
        }
        std::cout << std::endl;
    }

    bool block_is_free(int block_num)
    {
        return array[block_num] == -1;
    }

    void append(int num)
    {
        int start_block_num = hash(num);
        int block_num = start_block_num;
        int try_number = 0;
        while (block_num < 3*HASH_SIZE && !block_is_free(block_num))
        {
            try_number += 1;
            block_num = start_block_num + try_number*try_number;
        }
        
        if (block_num < 3*HASH_SIZE)
            array[block_num] = num;
        else // should do resize
            std::cout << "HASH TABLE IS FULL!" << std::endl;
            
    }

    bool find(int num)
    {
        int start_block_num = hash(num);
        int block_num = start_block_num;
        int try_number = 0;
        while (block_num < 3*HASH_SIZE && !block_is_free(block_num))
        {
            if (array[block_num] == num)
                return true;

            try_number += 1;
            block_num = start_block_num + try_number*try_number;
        }
        return false;
    }

    vector<int> array;
};

int main()
{
    QuadraticOpenAddressing hash_table;
    hash_table.print(); 
    std::cout << "-----------" << std::endl;

    hash_table.append(61);

    hash_table.append(22);

    hash_table.append(34);
    hash_table.append(43);
    hash_table.append(55);

    hash_table.append(71);
    hash_table.append(93);

    hash_table.print(); 

    
    std::cout << "-----------" << std::endl;

    std::cout << hash_table.find(72);
}
