#include <iostream>
#include <stdexcept>
#include <vector>

class Stack
{
private:
    std::vector<int>* stack;
    size_t size;
public:
    size_t length() const;
    void print() const;
    void push(int);
    int pop();
    Stack();
    ~Stack();
};

size_t Stack::length() const
{
    return this->size;
}

void Stack::print() const
{
    std::cout << "Stack has size " << this->size << std::endl;
    for (int i=0; i < this->size; i++)
    {
        std::cout << (*stack)[i] << " ";
    }
    std::cout << std::endl;
}

void Stack::push(int number)
{
    this->stack->push_back(number);
    this->size++;
}

int Stack::pop()
{
    if (size == 0)
    {
        throw std::range_error ("stack is empty, can't pop");
    }
    int return_val = (*stack)[this->size - 1];
    this->stack->pop_back();
    this->size--;
    return return_val;
}

Stack::Stack()
{
    this->stack = new std::vector<int>;
    this->size = 0;
}

Stack::~Stack()
{
    delete [] stack;
}

int main()
{
    Stack my_stack = Stack();
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);
    my_stack.print();
    std::cout << "Popped number " << my_stack.pop() << std::endl;
    my_stack.print();
    return 0;
}