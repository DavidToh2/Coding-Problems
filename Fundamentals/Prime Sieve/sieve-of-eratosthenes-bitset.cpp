#include <iostream>
#include <chrono>

#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

/*

Sieve of Eratosthenes. Implemented using a bitset.

Execution time:
10^7 numbers: 16ms
10^6 numbers: 1.6ms

*/

int primeSieve() {
    
    const int ncount = pow(10, 7);

    // The {} initialises all bitset values to 1
    auto *pb = new bitset<ncount+1>{};
    auto primes = (*pb).set();

    for (int i=3; pow(i, 2)<=ncount; i+=2) {
        if (primes[i]) {

            // We sieve the numbers with smallest prime factor i.
            for (int j=i; i*j<=ncount; j+=1) {
                primes[i*j] = false;
            }
        }
    }

    int pcount = 1;
    for (int i=3; i<=ncount; i+=2) {
        if (primes[i]) {
            pcount++;
        }
    }

    delete pb;

    return pcount;
}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << endl;
    auto start = chrono::high_resolution_clock::now();

    cout << "Number of primes: " << primeSieve() << endl;
    
    auto end = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << endl << "Your program took " << dur.count() << " microseconds!" << endl << endl;
    return 0;
}