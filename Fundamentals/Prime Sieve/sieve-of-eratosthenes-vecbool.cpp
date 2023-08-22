#include <iostream>
#include <chrono>

#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

/*

Sieve of Eratosthenes. Implemented using a vector<bool>.

Execution time:
10^9 numbers: 5763ms
10^8 numbers: 243ms
10^7 numbers: 14ms

*/


int primeSieve() {
    
    const int ncount = 1000000000;

    vector<bool> primes(ncount+1, true);

    for (int i=3; i*i<=ncount; i+=2) {
        if (primes[i]) {
            for (int j=i*i; j<=ncount; j+=i) {
                primes[j] = false;
            }
        }
    }

    int pcount = 1;
    for (int i=3; i<=ncount; i+=2) {
        if (primes[i]) {
            pcount++;
        }
    }

    return pcount;
}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << '\n';
    auto start = chrono::high_resolution_clock::now();

    cout << "Number of primes: " << primeSieve() << '\n';
    
    auto end = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << endl << "Your program took " << dur.count() << " microseconds!" << '\n' << '\n';
    return 0;
}