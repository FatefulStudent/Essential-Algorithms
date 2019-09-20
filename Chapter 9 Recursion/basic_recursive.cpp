#include <iostream>

using std::cout; 
using std::endl;

int factorial(int num)
{
    if (num == 0)
        return 1;

    return num*factorial(num-1);
}

int fibanocci(int num)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;

    return fibanocci(num-2)+fibanocci(num-1);
}

int main()
{
    cout << factorial(5) << " " << 5*4*3*2*1 << endl;
    cout << fibanocci(6) << " " << 8 << endl; 
}