#include <iostream>
#include <chrono>

#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

/*

Sieve of Eratosthenes. Implemented using a vector<bool>.

Execution time:
10^8 numbers: 16,577ms
10^7 numbers: 1,577ms
10^6 numbers: 967ms
10^5 numbers: 35ms

*/

long long primeSieve() {
    
    const long long ncount = pow(10, 7);
    long long pcount = ncount/2;

    vector<bool> primes(ncount+1, 1);

    for (long long i=4; i<=ncount; i+=2) {
        primes[i] = 0;
    }
    for (long long i=3; pow(i, 2)<=ncount; i+=2) {
        if (!primes[i]) {continue;}
        for (long long j=2; i*j<=ncount; j++) {
            long long c = i*j;
            if (primes[c]) {
                pcount--;
            }
            primes[c] = 0;
        }
    }

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