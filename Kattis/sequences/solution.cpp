#include <bits/stdc++.h>
using namespace std;

/*
Suppose the original sequence is n digits long, with x ones y zeroes and k ?s.
For an evaluated sequence with z zeroes, inversion index = (sum of positions of all zeroes) - z(z-1)/2.

There are (k choose i) evaluated sequences with y+i zeroes, each contributing -(y+i)(y+i-1)/2 to the total inversion index.
Hence, for the subtraction, we need to evaluate (k choose i) * -(y+i)(y+i-1)/2.

Each predetermined zero contributes 2^k * (its position) to the sum of positions of all zeroes.
Each question mark contributes half of that.
So the sum of positions should be: (sum of positions of predetermined zeroes) * 2^k + (sum of positions of question marks) * 2^(k-1).
*/

int main() {

}