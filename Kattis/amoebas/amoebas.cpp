#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <chrono>

using namespace std;

/*

https://open.kattis.com/problems/amoebas 

This is an easy flood fill problem.

Firstly, parse the user input into an array of strings "dish".

Next, iterate over all the cells in dish, from top-left to bottom-right.
Every time a '#' is found, perform a flood fill on all the '#'s it's connected to.
We do so by replacing the '#' with a number, representing the no. of the current amoeba, then
find all the cells around it with a '#', replacing those with the same number.

*/

int counter = 0;
int m = 0;
int n = 0;

void check_adjacent(vector<vector<string>> &v, int a, int b, int c) {

    // A B C
    // H X D
    // G F E

    v[a][b] = to_string(c);
    // Rows counted from 0 to m-1; columns counted from 0 to n-1
    if (a > 0) {
        if (v[a-1][b] == "#") {
            check_adjacent(v, a-1, b, c);        // B
        }
        if (b > 0) {
            if (v[a-1][b-1] == "#") {
                check_adjacent(v, a-1, b-1, c);  // A
            }
            if (v[a][b-1] == "#") {
                check_adjacent(v, a, b-1, c);    // H
            }
        }
        if (b < n-1) {
            if (v[a-1][b+1] == "#") {
                check_adjacent(v, a-1, b+1, c);  // C
            }
            if (v[a][b+1] == "#") {
                check_adjacent(v, a, b+1, c);    // D
            }
        }
    }
    if (a < m-1) {
        if (v[a+1][b] == "#") {
            check_adjacent(v, a+1, b, c);        // F
        }
        if (b > 0) {
            if (v[a+1][b-1] == "#") {
                check_adjacent(v, a+1, b-1, c);  // G
            }
            if (v[a][b-1] == "#") {
                check_adjacent(v, a, b-1, c);    // H
            }
        }
        if (b < n-1) {
            if (v[a+1][b+1] == "#") {
                check_adjacent(v, a+1, b+1, c);  // E
            }
            if (v[a][b+1] == "#") {
                check_adjacent(v, a, b+1, c);    // D
            }
        }
    }
}

int solution(vector<vector<string>> &v) {
    
    m = stoi(v[0][0]);
    n = stoi(v[0][1]);
    vector<vector<string>> dish;

    for (int i=1; i<=m; i++) {
        vector<string> ve;
        for (int j=0; j<n; j++) {
            string s(1, v[i][0][j]);
            ve.emplace_back(s);
        }
        dish.emplace_back(ve);
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (dish[i][j] == "#") {
                counter++;
                check_adjacent(dish, i, j, counter);
            }
        }
    }
    // for (int i=0; i<m; i++) {
    //     for (int j=0; j<n; j++) {
    //         cout << dish[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return counter;
}

int main(int argc, char* argv[]) {
    auto start = chrono::high_resolution_clock::now();

    string s, line;
    vector<vector<string>> v;
    while (getline(cin, line)) {
        vector<string> ve;
        istringstream ss(line);
        while (ss >> s) {
            ve.emplace_back(s);
        }
        v.emplace_back(ve);
    }

    cout << solution(v) << endl;
    
    // auto end = chrono::high_resolution_clock::now();
    // auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
    // cout << endl << "Your program took " << dur.count() << " microseconds!" << endl << endl;
    return 0;
}