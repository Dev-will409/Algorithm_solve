#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int dp[16] = { 0 };
    int p[16] = { 0 };
    int t[16] = { 0 };
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
        for (int j = 0; j < i; j++) {
            if (t[j] + j <= i &&i+t[i]<=n+1) {
                dp[i] = max(dp[i], dp[j]+p[i]);
            }
        }
    }
    int answer = 0;
    for (int i = 0; i <= n; i++) {
        answer = max(answer, dp[i]);
    }
    cout << answer;


    return 0;
}