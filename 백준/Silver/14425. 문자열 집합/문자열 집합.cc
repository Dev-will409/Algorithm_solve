#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int count = 0;

    set<string> str;


    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        str.insert(temp);
    }

    for (int i = 0; i < m; ++i) {
        string temp;
        cin >> temp;
        if(str.find(temp) != str.end()) ++count;
    }



    cout << count;
    return 0;
}