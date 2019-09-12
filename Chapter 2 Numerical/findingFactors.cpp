#include <iostream>
#include <vector>

using namespace std;

vector<int> naiveAlgorithm(int number)
{
    int divider = 2;
    vector<int> factors;
    while (divider < number)
    {
        while (number % divider == 0)
        {
            factors.push_back(divider);
            number /= divider;
        }
        divider++;
    }

    if (number > 1)
        factors.push_back(number); 
    return factors;
}

int main()
{
    
    auto factors = naiveAlgorithm(126);

    for (auto iter = factors.begin(); iter!=factors.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}