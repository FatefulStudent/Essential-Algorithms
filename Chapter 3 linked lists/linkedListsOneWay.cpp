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

    IntegerCell * findCell(int valueToFind)
    {
        IntegerCell * topList = top; 
        while ((*topList).nextCell != 0)
        {
            if ((*topList).value == valueToFind)
                return topList;
            topList = (*topList).nextCell;
        }
        return 0;
    }

    void Print()
    {
        IntegerCell * topList = top; 
        cout << (*topList).value << " ";
        while ((*topList).nextCell != 0)
        {
            topList = (*topList).nextCell;
            cout << (*topList).value << " ";
        }
        cout << endl;
    }

    IntegerCell * GetLast()
    {
        IntegerCell * topList = top; 
        while ((*topList).nextCell != 0)
        {
            topList = (*topList).nextCell;
        }
        return topList;
    }

    void AppendEnd(IntegerCell * newCell)
    {
        IntegerCell * lastCell = GetLast();
        (*lastCell).nextCell = newCell;
    }

    void AppendEnd(int newValue)
    {
        IntegerCell * newCell = new IntegerCell(newValue);
        AppendEnd(newCell);
    }

    LinkedList();
    LinkedList(IntegerCell*);
    ~LinkedList();
};

LinkedList::LinkedList()
{
    top = 0;
}

LinkedList::LinkedList(IntegerCell * topCell)
{
    top = new IntegerCell((*topCell).value);
}

LinkedList::~LinkedList()
{
    free(top);
}

LinkedList * constructNewList2()
{
    LinkedList * list = new LinkedList();
    
    IntegerCell *x1 = new IntegerCell(1);
    (*list).top = x1;

    IntegerCell *x2 = new IntegerCell(2);
    (*list).AppendEnd(x2);

    (*list).AppendEnd(3);
    (*list).Print();
    return list;
}

LinkedList * constructNewList1()
{
    LinkedList * list = new LinkedList();
    IntegerCell *x1 = new IntegerCell(1);
    (*list).top = x1;

    IntegerCell *x2 = new IntegerCell(2);
    (*(*list).top).nextCell = x2;

    IntegerCell *x3 = new IntegerCell(3);
    (*(*(*list).top).nextCell).nextCell = x3;
    (*list).Print();
    return list;
}

int main()
{
    LinkedList *x2 = constructNewList2();
    IntegerCell * foundedCell = (*x2).findCell(2);
    cout << "found " << (*foundedCell).value;
}