#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    string str = "Hello world!";
    vector<string> vec(3, str);

    // Concatenating a bunch of strings.

    string str1;
    for (int i=0; i<vec.size(); i++) {
        str1 += vec[i];
    }
    cout << str1 << '\n';

    ostringstream str2;
    copy(vec.begin(), vec.end(), ostream_iterator<string>(str2));
    cout << str2.str() << '\n';

    // Finding all occurences of a substring (sans overlap).

    string str3 = "ell";
    vector<size_t> positions;
    size_t pos = str1.find(str3, 0);
    while (pos != string::npos) {
        positions.emplace_back(pos);
        pos = str1.find(str3, pos + 1);
        // We can use rfind to start looking from the right of the string.
    }

    // Finding all occurences of a list of characters, passed as a string.

    string str4 = "aeiou";
    int vowelcount = 0;
    size_t pos = str1.find_first_of(str4, 0);
    while (pos != string::npos) {
        vowelcount++;
        pos = str1.find_first_of(str4, pos + 1);
    }

    // Splitting a string based on single character delimiter.

    stringstream str5(str1);
    vector<string> splitstr1;
    string item1;
    char delim = '!';
    while (getline(str5, item1, delim)) {
        splitstr1.emplace_back(item1);
    }

    // Splitting a string based on multi-character delimiter.

    string delim2 = "ll";
    vector<string> splitstr2;
    string item2;
    size_t begin = 0, end = 0;
    while ((end = str1.find(delim2, begin)) != string::npos) {
        item2 = str1.substr(begin, end);
        splitstr2.emplace_back(item2);
        begin = end + delim2.length();
    }

    // Sorting a string, or an array of strings, lexicographically.

    string strsort(str1);
    sort(strsort.begin(), strsort.end());
    cout << strsort;
    vector<string> sortstr1{"Apple", "APPLE", "Bear", "Bearing", "bear", "bear"};
    sort(sortstr1.begin(), sortstr1.end());

    // Counting the number of occurences of each string in a vector. Use an unordered_map.

    unordered_map<string, int> strcount;
    for (string s : sortstr1) {
        strcount[s]++;
    }
    int max = 0; string maxstr;
    for (auto i : strcount) {
        if (i.second > max) {
            max = i.second;
            maxstr = i.first;
        }
    }
}