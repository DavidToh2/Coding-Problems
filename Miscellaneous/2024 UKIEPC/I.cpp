#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void soln(ll N, ll M){
    for(int i = 0; i < N; i++){
        if(i == 0){
            int remaining = M - 2 * (N - 1);
            cout << 1 << " " << 1 << " " << remaining - 1 << " " << remaining << '\n';
        }
        else if(i == N - 1){
            int remaining = M - (N - 1);
            int chosen = remaining / 2 + 1;
            cout << chosen << " " << remaining << " " << 1 << " " << 2 << '\n';
        }
        else{
            cout << 1 << " " << 1 << " " << 1 << " " << 2 << '\n';
        }
    }
}

int main(){
    ll n, m;
    cin >> n >> m;
    soln(n, m);

}