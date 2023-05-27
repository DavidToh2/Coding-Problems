#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

void solution() {
    // Code here
    cout << "Hello there!" << endl;
    return;
}

int main(int argc, char* argv[]) {
    cout << endl;
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
    cout << endl << "Your program took " << dur.count() << " microseconds!" << endl << endl;
    return 0;
}