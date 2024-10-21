#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, p; int k;
    cin >> n >> k >> p;
    ll m;
    cin >> m;

    if ((k < p) && (n > k)) {
        cout << "impossible" << endl;
        return 0;
    }

    // minheap (no. of occurences, colour)
    priority_queue<pair<ll, ll>> h;
    // arr[colour] = no. of occurences
    vector<ll> occ(k+1, 0);
    // bitset[colour] = whether it's invalid
    bitset<100001> b;
    // q[i] = ith previous element. Access q[p] to get pth previous element
    deque<ll> q;

    // Get the first m stripes and check them
    ll c;
    vector<ll> existing;
    for (int i = 0; i<m; i++){
        cin >> c;
        occ[c] -= 1;
        
        if (i >= p) {
            ll c2 = q.back();
            q.pop_back();
            b[c2] = false;
        }

        if (b[c]) { cout << "impossible\n"; return 0; }
        q.emplace_front(c);
        b[c] = true;
        existing.emplace_back(c);
    }

    for (auto i : existing) { cout << i << " "; }

    // Store the n-p valid stripe colours into the minheap
    for (int i=1; i<=k; i++) {
        if (!b[i]) { 
            h.emplace(make_pair(occ[i], i)); // cout << i << " is valid and has been added with value "<< occ[i] << "\n"; 
        }
    }

    // Generate n-m more colours
    for (int i=0; i<n - m; i++) {

        auto c = h.top();
        h.pop();
        cout << c.second << " ";
        occ[c.second]--;
        q.emplace_front(c.second);
        
        ll c2 = q[p];

        h.push(make_pair(occ[c2], c2));
        q.pop_back();
    }
}