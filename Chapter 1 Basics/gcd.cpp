#include <iostream>
using namespace std;

int greatestCommonDivider(int a, int b)
{
    int remainder;

    while (b!=0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

int main()
{
    int a, b;
    cout << "Enter a, b: ";
    cin >> a >> b;

    cout << greatestCommonDivider(a, b);
}