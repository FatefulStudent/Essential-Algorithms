#include <iostream>
#include <vector>

using namespace std;

// just cycling every integer until our number 
// and checking whether it is a divider
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

// we dont need to check all even numbers after checking 2
// we need to perform search until sqrt(number)
// updating maxfactor based on number
vector<int> improvedAlgorithm(int number)
{
    vector<int> factors;

    while (number % 2 == 0)
    {
        factors.push_back(2);
        number /= 2;
    }
    int oddDivider = 3;
    double maxFactor = sqrt((double)number);
    while (oddDivider <= maxFactor)
    {
        while (number % oddDivider == 0)
        {
            factors.push_back(oddDivider);
            number /= oddDivider;
            maxFactor = sqrt((double)number);
        }
        oddDivider += 2;
    }

    if (number != 1)
        factors.push_back(number);

    return factors;
}

int main()
{
    vector<int> factors;
    factors = naiveAlgorithm(126);

    for (auto iter = factors.begin(); iter!=factors.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    factors = improvedAlgorithm(126);

    for (auto iter = factors.begin(); iter!=factors.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}