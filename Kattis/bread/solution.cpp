#include <bits/stdc++.h>
#include <chrono>

using namespace std;

/* 
Merge sort with inversion index.
*/

void print_vector(vector<int> &v) {
    int n = v.size();
    for (int i=0; i<n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> merge_two_sorted_vectors(int &inversion_index, vector<int> &va, vector<int> &vb) {

    // cout << "Merging the following two vectors:" << endl;
    // print_vector(va);
    // print_vector(vb);

    int la = va.size(), lb = vb.size();
    vector<int> vc(la + lb, 0);
    int i = 0, j = 0;
    while (i != la && j != lb) {
        if (va[i] > vb[j]) {
            vc[i+j] = vb[j];
            j++;
            inversion_index += (la-i);
        } else {
            vc[i+j] = va[i];
            i++;
        }
    }
    while (i != la) {
        vc[i+j] = va[i];
        i++;
    }
    while (j != lb) {
        vc[i+j] = vb[j];
        j++;
    }

    // cout << "Result:" << endl;
    // print_vector(vc);
    return vc;
}

void merge_sort(int &inversion_index, vector<int> &v) {

    // cout << "Merge sorting the following vector:" << endl;
    // print_vector(v);

    int a = v.size();
    int d = a/2;

    if (a == 1) return;
    if (a == 2) {
        if (v[0] > v[1]) {
            int c = v[0];
            v[0] = v[1];
            v[1] = c;
            inversion_index++;
        }
        return;
    }
    vector<int> vec1, vec2;
    for (int i=0; i<d; i++) {
        vec1.emplace_back(v[i]);
    }
    for (int i=d; i<a; i++) {
        vec2.emplace_back(v[i]);
    }

    merge_sort(inversion_index, vec1);
    merge_sort(inversion_index, vec2);

    vector<int> v3 = merge_two_sorted_vectors(inversion_index, vec1, vec2);
    for (int i=0; i<a; i++) {
        v[i] = v3[i];
    }

    // cout << "Result:" << endl;
    // print_vector(v);
    // cout << "Inversion index at this point is " << inversion_index << endl;

}

void solution(int n, vector<int> &start, vector<int> &end) {
    
    map<int, int> m;
    for (int i=0; i<n; i++) {
        m[end[i]] = i;
    }
    for (int i=0; i<n; i++) {
        start[i] = m[start[i]];
    }

    int inversion_index = 0;

    merge_sort(inversion_index, start);

    // cout << inversion_index << endl;
    if (inversion_index % 2 == 0) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> st, e;
    string s;
    for (int i=0; i<n; i++) {
        cin >> s;
        st.emplace_back(stoi(s));
    }
    for (int i=0; i<n; i++) {
        cin >> s;
        e.emplace_back(stoi(s));
    }

    solution(n, st, e);
}