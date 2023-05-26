#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

#include <chrono>

using namespace std;

/*

https://open.kattis.com/problems/wheresmyinternet

This is a problem regarding connected components in graphs.

Firstly, parse the graph edges into a "partial" adjacency matrix that only stores pairs of connected vertices.
This is because storing all pairs of vertices would require n^2 memory, which is too large (n <= 200000).

Next, construct the component connected to vertex 1 using a vector<bool>. All connected vertices will be represented with bit 1.
Starting with vertex 1, perform a DFS on the "partial" adjacency matrix.
The DFS is performed using a queue container, where elements are inserted into the back and removed from the front.
Repeatedly check as-yet-unchecked vertices in the queue, then remove the checked vertices, until the queue is empty.

*/

void solution(vector<vector<int>> &v) {
    int n = v[0][0];
    int m = v[0][1];
    vector<vector<int>> adj(n+1, vector<int>(0));

    for (int i=1; i<=m; i++) {
        int a = v[i][0];
        int b = v[i][1];
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    vector<bool> connected(n+1, 0);
    queue<int> connectedHouses;
    connected[1] = 1;
    connectedHouses.emplace(1);

    while (!connectedHouses.empty()) {
        int c = connectedHouses.front();
        for (int d : adj[c]) {
            if (!connected[d]) {
                connected[d] = 1;
                connectedHouses.emplace(d);
            }
        }
        connectedHouses.pop();
    }

    // for (int i=1; i<=n; i++) {
    //     cout << connected[i] << " ";
    // }

    bool all_connected = true;
    for (int i=1; i<=n; i++) {
        if (!connected[i]) {
            all_connected = false;
            cout << i << endl;
        }
    }
    if (all_connected) {
        cout << "Connected" << endl;
    }
}

int main(int argc, char* argv[]) {
    // cout << endl;
    // auto start = chrono::high_resolution_clock::now();

    string s, line;
    vector<vector<int>> v;
    while (getline(cin, line)) {
        vector<int> ve;
        istringstream ss(line);
        while (ss >> s) {
            ve.emplace_back(stoi(s));
        }
        v.emplace_back(ve);
    }

    solution(v);
    
    // auto end = chrono::high_resolution_clock::now();
    // auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
    // cout << endl << "Your program took " << dur.count() << " microseconds!" << endl << endl;
    return 0;
}