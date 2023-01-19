#include <iostream>
#include <algorithm>

using namespace std;

int arr[301] = {0,};
int dp[301][2] = {0,};

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", arr+i);
    }

    dp[1][0] = arr[1];
    dp[2][0] = dp[1][0] + arr[2];
    dp[2][1] = arr[2];
    for (int i = 3; i <= n; ++i) {
        dp[i][0] = dp[i-1][1] + arr[i];
        dp[i][1] = max(dp[i-2][0], dp[i-2][1]) + arr[i];
    }

    printf("%d", max(dp[n][0], dp[n][1]));

    return 0;
}
