#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void solution() {
    // Code here
    cout << "Hello there!" << '\n';
    return;
}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    auto start = chrono::high_resolution_clock::now();

    // string s, line;
    // vector<vector<string>> v;
    // while (getline(cin, line)) {
    //     vector<string> ve;
    //     istringstream ss(line);
    //     while (ss >> s) {
    //         ve.emplace_back(s);
    //     }
    //     v.emplace_back(ve);
    // }

    solution();
    
    auto end = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << endl << "Your program took " << dur.count() << " microseconds!" << '\n' << '\n';
    return 0;
}