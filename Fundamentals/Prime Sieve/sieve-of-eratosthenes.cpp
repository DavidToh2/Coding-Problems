#include <iostream>
#include <chrono>

#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

/*

Sieve of Eratosthenes. Implemented using a bitset.

Execution time:
10^7 numbers: 630ms
10^6 numbers: 124ms
10^5 numbers: 19ms

*/

long long primeSieve() {
    
    const long long ncount = pow(10, 5);

    bitset<ncount+1> *primesPointer = new bitset<ncount+1>;
    bitset<ncount+1> primes = *primesPointer;
    primes.set();
    for (long long i=4; i<=ncount; i+=2) {
        primes[i] = 0;
    }
    for (long long i=3; pow(i, 2)<=ncount; i+=2) {
        if (!primes[i]) {continue;}
        for (long long j=2; i*j<=ncount; j++) {
            primes[i*j] = 0;
        }
    }

    long long pcount = primes.count() - 2;
    delete primesPointer;

    return pcount;
}

int main(int argc, char* argv[]) {
    cout << endl;
    auto start = chrono::high_resolution_clock::now();

    cout << "Number of primes: " << primeSieve() << endl;
    
    auto end = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << endl << "Your program took " << dur.count() << " microseconds!" << endl << endl;
    return 0;
}