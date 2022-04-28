#include <iostream>
#include "algorithm"

using namespace std;

int main() {
    string a, first, second, third, minStr;
    minStr = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

    cin >> a;

        for (int j = 1; j < a.size() - 1; ++j) {
            for (int k = j + 1; k < a.size(); ++k) {
                first = a.substr(0,j);
                reverse(first.begin(), first.end());
                second = a.substr(j,k-j);
                reverse(second.begin(), second.end());
                third = a.substr(k, a.size()-k);
                reverse(third.begin(), third.end());
                string newStr = first+second+third;
                if(newStr < minStr) minStr = newStr;
            }
        }

        cout << minStr << endl;

    return 0;
}
