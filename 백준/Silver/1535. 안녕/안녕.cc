#include <iostream>
using namespace std;

int n, health[21], happy[21], dp[101];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> happy[i];
    }

    for (int i = 0; i <n; i++) {
        for (int j = 100; j >= health[i]; j--) {
            dp[j] = max(dp[j], dp[j - health[i]] + happy[i]);
        }
    }

    cout << dp[99];

}