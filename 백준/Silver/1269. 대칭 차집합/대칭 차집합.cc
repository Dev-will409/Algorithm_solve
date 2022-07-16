#include <iostream>
#include <set>

using namespace std;

int main() {

    int a ,b;

    set<int> set_a;
    set<int> set_b;
    cin >> a >> b;

    for (int i = 0; i < a; ++i) {
        int temp;
        cin >> temp;
        set_a.insert(temp);
    }

    for (int i = 0; i < b; ++i) {
        int temp;
        cin >> temp;
        set_b.insert(temp);
    }

    int a_count = 0;
    int b_count = 0;

    for (auto i : set_b) {
        if(set_a.find(i) == set_a.end()){
            ++b_count;
        }
    }

    for (auto i : set_a) {
        if(set_b.find(i) == set_b.end()){
            ++a_count;
        }
    }

    cout << a_count + b_count << endl;
    return 0;
}