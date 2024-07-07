#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
// colour = 0 means unsearched
// colour = 1 means searching
// colour = 2 means searched, nothing here
vector<int> colour;

bool dfs(int v, vector<vector<int>> &adj) {
    colour[v] = 1;
    for (int u : adj[v]) {
        if (colour[u] == 0) {
            parent[u] = v;
            if (dfs(u, adj)) {return true;}
        } else if (colour[u] == 1) {
            return true;
        }
    }
    colour[v] = 2;
    return false;
}

int main() {
    int C; cin >> C;
    for (int i=0; i<C; i++) {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>());
        vector<vector<int>> adj(n, vector<int>());
        for (int j=0; j<n; j++) {
            v[j].emplace_back(j);
        }

        bool loop_found = false;

        int a, b; 
        for (int j=0; j<m; j++) {
            cin >> a >> b;
            // adj[a].emplace_back(b);
            // adj[b].emplace_back(a);
            // if (v[a][0] == v[b][0]) {
            //     loop_found = true;
            //     break;
            // } else {
            //     v[a].insert(v[a].end(), v[b].begin(), v[b].end());
            //     for (int k : v[b]) {
            //         v[k] = v[a];
            //     }
            // }
        }

        // if (loop_found) {
        //     dfs(a, adj);
        //     vector<int> solution = {b}; int cur = b;
        //     while (cur != a) {
        //         cur = parent[cur];
        //         solution.emplace_back(cur);
        //     }

        //     sort(solution.begin(), solution.end());

        //     for (int k=1; k<solution.size() - 1; k++) {
        //         cout << solution[k] << " ";
        //     }
        //     cout << solution[solution.size() - 1] << '\n';
        // } else {
        //     cout << "-1";
        // }
    }

}