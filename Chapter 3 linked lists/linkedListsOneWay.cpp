#include <iostream>
using namespace std;

class IntegerCell
{
public:
    int value;
    IntegerCell * nextCell;
    IntegerCell();
    IntegerCell(int);
    ~IntegerCell();
};

IntegerCell::IntegerCell()
{
    value = 0;
    nextCell = 0;
}

IntegerCell::IntegerCell(int a)
{
    value = a;
    nextCell = 0;
}

IntegerCell::~IntegerCell()
{
    free(nextCell);
}

class LinkedList
{
public:
    IntegerCell * top;
    LinkedList(IntegerCell);
    ~LinkedList();
};

LinkedList::LinkedList(IntegerCell topCell)
{
    top = new IntegerCell(topCell.value);
}

LinkedList::~LinkedList()
{
    free(top);
}


int main()
{
    IntegerCell *x = new IntegerCell(1);
    cout << (*x).value << endl;
}