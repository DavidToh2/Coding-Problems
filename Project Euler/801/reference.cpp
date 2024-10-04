#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <map>
#include <unordered_map>

/*
Reference code obtained from the internal thread https://projecteuler.net/thread=801.

Used to debug my own code after the correct algo had been attained.
Improvements discovered:
- OEIS A024078 gives a direct formula for the number of solutions
- powmod should start with a "base %= mod", otherwise strange behaviour may occur with large numbers
- for the prime sieve, maintaining a vector of primes is more efficient in the long run for checking primality of large numbers
- for the prime sieve, the vector of primes should store all primes up to 10^8 rather than 10^4 (bug that cost me some time)
*/

const long long L=1e16,R=1e16+1e4;
const long long MOD=993353399;
const int UP=1e8;
bool sieve[UP+100];
int primes[UP],top=0;
void init()
{
    for (int i=2;i<=UP;++i)
        if (!sieve[i])
        {
            primes[top++]=i;
            for (int j=i;j<=UP/i;++j)
                sieve[i*j]=true;
        }
}
long long powmod(long long x,long long y,long long mod)
{
    long long ret=1;
    for (x%=mod;y;y>>=1,x=x*x%mod)
        if (y&1) ret=ret*x%mod;
    return ret;
}
void decompose(long long n,std::unordered_map<long long,int> &li)
{
    for (int i=0;i<top && primes[i]<=n/primes[i];++i)
        for (;n%primes[i]==0;n/=primes[i],li[primes[i]]++);
    if (n>1) li[n]++;
}
int main()
{
    init();
    long long ans=0;
    #pragma omp parallel for reduction(+:ans) schedule(guided)
    for (long long i=std::max(2LL,L);i<=R;++i)
    {
        bool isprime=true;
        for (int j=0;j<top && primes[j]<=i/primes[j];++j)
            if (i%primes[j]==0)
            {
                isprime=false;
                break;
            }
        if (!isprime) continue;
        const long long moduli=i-1;
        std::unordered_map<long long,int> factors;
        decompose(moduli,factors);
        long long temp=1;
        for (const auto &j:factors)
        {
            long long p=j.first,e=j.second;
            // printf("%lld^%i, ", p, e);
            long long t = (powmod(p,3*e,MOD)+powmod(p,3*e-1,MOD)-powmod(p,2*e-1,MOD))%MOD;
            temp=(temp*t)%MOD;
            // printf("temp: %lld, currsoln: %lld\n", t, temp);
        }
        long long sq = powmod(i-1,2,MOD);
        // printf("sq: %lld\n", sq);
        temp=(temp+sq)%MOD;
        ans+=temp;
        if (i % 100 == 1) printf("%lld: %lld\n",i,temp);
    }
    printf("%lld\n",ans%MOD);
    return 0;
}
