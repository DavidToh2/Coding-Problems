#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void soln(vector<ll> &present, ll n, ll k, ll p){
    priority_queue<pair<ll, ll>> freqOrder;
    unordered_map<ll, ll> freqMap;
    unordered_set<ll> invalidColors;
    for(ll i = n - 1; i >= max((ll)0, n - k + 1); i--){
        invalidColors.insert(present[i]);
    }
    for(int i = 1; i <= n; i++){
        freqMap[i] = 0;
    }
    for(int it: present){
        freqMap[it] ++;
    }
    for(auto it: freqMap){
        freqOrder.push({it.second, it.first});
    }
    while(present.size() < n){
        while(true){
            if(freqOrder.size() == 0){
                cout << "Impossible" << endl;
            }
            else{
                pair<ll, ll> topEle = freqOrder.top();
                ll topColour = topEle.second;
                if(invalidColors.find(topColour) == invalidColors.end()){
                    ll top
                }
                else{
                    freqOrder.pop();
                }
            }
        }
    }
}

int main(){
    ll n, k, p;
    cin >> n >> k >> p;
    vector<ll> present;
    ll m;
    cin >> m;
    for(int i = 0; i < m; i++){
        ll ele;
        cin >> ele;
        present.push_back(ele);
    }
    soln(present, n, k, p);
}