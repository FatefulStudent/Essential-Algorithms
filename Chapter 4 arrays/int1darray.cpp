#include <algorithm>
#include <iostream>

class int1darray
{
private:
    size_t size;
    int * data;
public:
    size_t size() const;
    void swap(int1darray &other);
    int get(size_t i) const;
    int &get(size_t i);
    void resize(size_t new_size);

	int1darray &operator=(const int1darray &other);

    int1darray();
    explicit int1darray(int);
    int1darray(int1darray const &other);
    ~int1darray();
};

void int1darray::resize(size_t new_size)
{
    int1darray new_array = int1darray(new_size);
    size_t smaller_size = this->size > new_size ? new_size : this->size;

    for (size_t i = 0; i < smaller_size; i++)
    {
        new_array.data[i] = this->data[i];
    }

    this->swap(new_array);
}

int int1darray::get(size_t i) const
{
    return this->data[i];
}

int& int1darray::get(size_t i)
{
    return this->data[i];
}

size_t int1darray::size() const
{
    return this->size;
}

void int1darray::swap(int1darray &other)
{
    std::swap(other.size, this->size);
    std::swap(other.data, this->data);
}

int1darray & int1darray::operator=(const int1darray &other)
{
    if (this != &other)
        int1darray(other).swap(*this);
    return *this;
}

int1darray::int1darray()
{
    this->size = 0;
    this->data = 0;
}

int1darray::int1darray(int size)
{
    this->size = size;
    this->data = new int [size];

    for (size_t i = 0; i < size; i++)
        data[i] = 0;
}

int1darray::int1darray(int1darray const &other)
{
    this->size = other.size;
    this->data = new int[this->size];
    for (size_t i = 0; i < this->size; i++)
        data[i] = other.data[i];
    
}

int1darray:: 

int1darray::~int1darray()
{
    delete [] data;
}


int main()
{

}