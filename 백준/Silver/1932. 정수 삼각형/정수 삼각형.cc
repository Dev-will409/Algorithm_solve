#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501] = {0,};
int dp[501][501] = {0,};

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    dp[1][1] = arr[1][1];
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
        }
    }

    printf("%d", *max_element(dp[n], dp[n]+n+1));

    return 0;
}
