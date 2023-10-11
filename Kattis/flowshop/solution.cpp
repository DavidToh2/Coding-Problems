#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, N;
    cin >> N >> M;
    vector<vector<int>> P(N, vector<int>(M, 0));

    cin >> P[0][0];
    int c;
    for (int j=1; j<M; j++) {
        cin >> c;
        P[0][j] = P[0][j-1] + c;
    }
    cout << P[0][M-1] << " ";

    for (int i=1; i<N; i++) {
        cin >> c;
        P[i][0] = P[i-1][0] + c;
        for (int j=1; j<M; j++) {
            cin >> c;
            if (P[i-1][j] > P[i][j-1]) {
                P[i][j] = P[i-1][j] + c;
            } else {
                P[i][j] = P[i][j-1] + c;
            }
        }
        cout << P[i][M-1] << " ";
    }
    // P[i][j] is the time required for swather i to complete stage j.
}