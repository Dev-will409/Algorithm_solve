#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string s;

    cin >> s;

    set<string> sets;

    for (int i = 0; i < s.length(); ++i) {
        for (int j = 1; j <= s.length()-i; ++j) {
            sets.insert(s.substr(i,j));
        }
    }

    cout << sets.size() <<endl;

    return 0;
}