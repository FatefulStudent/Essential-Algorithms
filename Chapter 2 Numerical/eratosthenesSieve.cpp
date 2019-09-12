#include <iostream>
#include <vector>
using namespace std;

vector<int> findPrimes(int max_num)
{
    bool * isPrime = new bool[max_num+1];
    
    // initializing array with false
    for (int num = 0; num <= max_num; num++)
        isPrime[num] = true;

    // all even numbers are not primes    
    for (int num = 4; num <= max_num; num += 2)
        isPrime[num] = false;

    int nextPrimeToSieve = 3;
    int maxPrimeToSieve = (int)sqrt((double)max_num);
    cout << "max prime to sieve "<< maxPrimeToSieve << endl;
    while (nextPrimeToSieve <= maxPrimeToSieve)
    {
        cout << "nextPrimeToSieve working "<< nextPrimeToSieve << endl;
        // nextPrime's multipliers are composite
        for (int num = nextPrimeToSieve*2; num <= max_num; num+=nextPrimeToSieve)
            isPrime[num] = false;

        // ignoring composite numbers and trying to find next prime
        nextPrimeToSieve += 2;
        while (nextPrimeToSieve <= max_num && !isPrime[nextPrimeToSieve])
        {
            cout << "nextPrimeToSieve skipping "<< nextPrimeToSieve << endl;
            nextPrimeToSieve += 2;
        }
            
    }

    vector<int> primes;
    for (int num = 2; num <= max_num; num++)
    {
        if (isPrime[num])
            primes.push_back(num);
    }

    return primes;
}

int main()
{
    vector<int> primes = findPrimes(121);

    for (auto iter = primes.begin(); iter!=primes.end(); iter++)
        cout << *iter << " ";

}