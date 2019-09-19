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


int main()
{
    SeparateChaining hash_table;
    hash_table.print(); 
    std::cout << "-----------" << std::endl;

    hash_table.append(10);
    hash_table.append(111);

    hash_table.append(28);
    hash_table.append(38);

    hash_table.print(); 

    
    std::cout << "-----------" << std::endl;

    std::cout << hash_table.find(111);
}
