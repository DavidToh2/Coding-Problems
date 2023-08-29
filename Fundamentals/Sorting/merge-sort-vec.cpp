#include <bits/stdc++.h>
#include <chrono>

using namespace std;

/*
Merge-sort (Space-efficient semi-in-place version) using vectors (yes, not efficient).

Complexity: O(n log(n))
Space efficiency: factor of 1/2 compared to default merge sort.

Time taken (without compiler optimisations):
10^4: 9.188 ms
10^5: 87.57 ms
10^6: 891.7 ms
10^7: > 3 s

Time taken (with compiler optimisations):
10^4: 1.006 ms
10^5: 8.725 ms
10^6: 115.5 ms
10^7: 1.095 s
10^8: 12.203 s

Note: you can also implement this algorithm using a linked list, which is arguably more efficient in rotating the list
(i.e. doing something like A B C D E -> B C D E A).
However, doing this using C++'s inbuilt linked list is really annoying because the list<int>::iterators will keep switching
positions whenever the list is rotated.

*/

void print_vector(vector<int> &v) {
    for (auto i = v.begin(); i != v.begin() + 100; i++) {
        printf("%i ", *i);
    }
    printf("\n");
}

void join_sorted_lists(vector<int> &v, vector<int> &v1) {

    // printf("Joining the following two vectors:\n");
    // print_vector(v);
    // print_vector(v1);

    vector<int>::iterator it = v.end() - 1, it1 = v1.end() - 1;
    v.insert(v.end(), v1.size(), 0);
    vector<int>::iterator it0 = v.end() - 1;

    do {
        if (*it > *it1) {
            *it0 = *it;
            it--;
        } else {
            *it0 = *it1;
            it1--;
        }
        it0--;
    }
    while (it != it0);

    v1.clear();

}

void merge_sort(vector<int> &v) {

    // printf("Merge sorting the following vector:\n");
    // print_vector(v);

    int l = v.size(); int a = l/2;
    if (l <= 2) {
        if (l == 2) {
            if (v[0] > v[1]) {
                int c = v[1]; v[1] = v[0]; v[0] = c;
            }
        }
        return;
    }

    vector<int> v1;
    move((v.begin() + a), v.end(), back_inserter(v1));
    v.erase((v.begin() + a), v.end());
    
    merge_sort(v);
    merge_sort(v1);

    join_sorted_lists(v, v1);

    return;
}

int main(int argc, char* argv[]) {

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    scanf("%i", &n);
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    random_shuffle(v.begin(), v.end());
    
    auto start = chrono::high_resolution_clock::now();

    merge_sort(v);
    
    auto end = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::microseconds>(end - start);

    printf("Sorted sequence:\n");
    print_vector(v);

    printf("Your program took %ld microseconds!", dur.count());
    return 0;
}