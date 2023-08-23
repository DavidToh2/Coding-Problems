#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>

#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

const long long MOD = 993353399;
const int N = 100000000;
vector<bool> isprime(N+1, true);
vector<int> primes;

/*
Runtime:
Main solution (1e16 to 1e16+1e6) takes 436.2s.
1e16 to 1e16+1e5 takes 44.294s.
1e16 to 1e16+1e4 takes 4.862s.

Answer: 638129754
*/

void primesieve() {
    primes.emplace_back(2);
    for (int i=3; i<N; i+=2) {
        if (isprime[i]) {
            primes.emplace_back(i);
            if (i<sqrt(N)) {
                for (int j=i; i*j<=N; j++) {
                    isprime[i*j] = false;
                }
            }
        }
    }
}

unsigned long long powmod(long long p, int e, long long mod) {
    long long ans = 1;
    p %= mod;
    while (e > 0) {
        ans = (ans * p) % mod;
        e--;
    }
    return ans;
}

    // For any number x and for each residue class y (mod p), check if y^x belongs in the residueList of x.
    // If it's inside, then among the p-1 numbers x^y, x^(y+p), x^(y+2p), ..., x^(y+(p-2)p), residueCycles[x] of those will be
    // congruent to y^x (mod p). This gives us the solutions amongst the numbers {y, y+p, y+2p, ..., y+(p-2)p}.
    // If it's not inside, then no solutions exist.

    // In order to check all numbers x, we use the fact that y^(x+p) = y^(x+1) (mod p). So, check if y^(x+1) belongs in the residueList of x.
    // If it's inside, repeat the reasoning as above. If it's not inside, then no solutions exist.
    // Using this reasoning, to check y^x, y^(x+p), y^(x+2p), ..., y^(x+(p-2)p), it suffices to check y^x, y^(x+1), y^(x+2), ..., y^(x+(p-2)).
    // This is equivalent to just checking 1, y, y^2, ..., y^(p-2), with the number of occurences of solutions not changing.
    // There are residuePeriod[y] distinct values in the above, with each solution occuring residueCycle[y] times.

    // In summary, if y^k in residueList[x], then contributes residueCycles[x]*residueCycles[y] solutions.
    // So each pair of residue classes (x, y) contributes with multiplicity equal to the number of common elements in 
    // residueList[x] and residueList[y].

    // Hence, what we can do is bijectively look at the residues k instead. For each pair (x, y) in residueInList[k], add 
    // residueCycles[x]*residueCycles[y] to the total amount. Switching (x, y) to (y, x) gives a different solution, and (x, x) are also
    // considered solutions. Hence, the desired sum can simply be gotten with sum(residueCycles[x])^2.

int f_old(int p) {
    vector<int> residueCycles(p, 0);
    vector<vector<int>> residueInList(p, vector<int>(0));

    // Generate residueList and residueCycles.
    // If k is in residueList[x], then residueInList[k][x] = true.
    for (int i=1; i<p; i++) {
        int j = 1;
        int t = i;
        residueInList[i].emplace_back(t);
        while (t != 1) {
            t = (t * i) % p;
            residueInList[t].emplace_back(i);
            j++;
        }
        residueCycles[i] = (p-1)/j;
    }

    unsigned int solutions = 0;

    // Calculate sum.
    for (int i=1; i<p; i++) {
        int l = residueInList[i].size();
        unsigned int sum = 0;
        if (residueCycles[i] == 1) {
            sum += l;
        } else {
            for (int j=0; j<l; j++) {
                sum = sum + residueCycles[residueInList[i][j]];
            }
        }
        unsigned int a = (sum*sum) % MOD;
        solutions = (solutions + a) % MOD;
    }

    // Add (p-1)^2 for those solutions where x, y are both zero;
    solutions = (solutions + (p-1)*(p-1)) % MOD;
    return solutions;
}

    // The above algorithm can be optimised using primitive roots. Let g^a=x and g^b=y; note that, using the same reasoning, adding p to x and y
    // will not change the base, but will increase the exponent by 1, thereby allowing us to iterate over all the possible residues. Hence,
    // we're trying to find the number of solutions to g^(ay) = g^(bx) (mod p), or ay = bx (mod p-1), where a, b, x, y are completely independent!

    // To do this we decompose p-1 into its constituent prime factors. Then, compute the number of solutions to the above congruence for each p^e.
    // Finally, multiply all of these together. It turns out that the number of solutions has a formula (OEIS A020478): p^(2*e - 1)*(p^(e+1) + p^e - 1).

    // This gives us a direct formula for the number of solutions!

long long f(long long n) {
    unordered_map<long long, int> factors;
    long long r = n-1;
    // Decompose p-1 into its constituent factors.
    for (int j : primes) {
        while (r % j == 0) {
            r /= j;
            factors[j]++;
            if (n == 20123) {
                printf("%i ",j);
            }
        }
        if (r == 1) {
            break;
        }
    }
    if (r != 1) {
        factors[r]++;
    }

    long long solution = 1;
    // For each prime power, compute its contribution to the answer.
    for (const auto &a : factors) {
        long long p = a.first;
        int e = a.second;
        long long temp = (powmod(p, 2*e-1, MOD) * (powmod(p, e+1, MOD) + powmod(p, e, MOD) - 1)) % MOD;
        solution = (solution * temp) % MOD;
    }
    long long sq = powmod(n-1, 2, MOD);
    solution = (solution + sq) % MOD;
    return solution;
}

int solution() {
    primesieve();

    // Note that for p=2, the pairs (x, y) = (1, 1) and (2, 2) work too. So we just add them in manually.
    long long lower = pow(10, 16);
    long long upper = lower + pow(10, 4);
    long long answer = 0;

    // #pragma omp parallel for reduction(+:answer) schedule(guided)
    for (long long n=lower+1; n<upper; n+=2) {
        bool ip = true;
        for (int p : primes) {
            if (n % p == 0 && n > p) {
                ip = false;
                break;
            }
            if (n == p) { break; }
        }
        if (!ip) { continue; }
        long long fa = f(n);
        answer = answer + fa;
        if (n % 100 == 1) {
            printf("Current number: %lld, ", n);
            printf("Current output: %lld\n", fa);
        }
        // printf("Current answer: %lld\n", answer);
    }
    return answer%MOD;
}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    auto start = chrono::high_resolution_clock::now();

    cout << "Answer: " << solution() << '\n';
    
    auto end = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Your program took " << dur.count() << " microseconds!" << '\n' << '\n';
    return 0;
}