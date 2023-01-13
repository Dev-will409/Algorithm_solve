#include <iostream>

using namespace std;

long long dp[202][102] = {0,};

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    dp[0][0] = 1;
    for (int i = 0; i <= n+m; ++i) {
        for (int j = 0; j <= i; ++j) {
            if(j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            if(dp[i][j] > 1e9) dp[i][j] = 1e9;
        }
    }

    if(dp[n+m][m] < k) {
        printf("%d",-1);
        return 0;
    }

    char ans[201] = {0,};

    int len = n+m;
    int l = n+m;
    int i = 0;
    while(len--){
        if(dp[len][m] >= k){
            ans[i] = 'a';
        }
        else{
            m -= 1;
            ans[i] = 'z';
            k -= dp[len][m+1];
        }
        i += 1;
    }
    for (int j = 0; j < l; ++j) {
        printf("%c",ans[j]);
    }

    return 0;
}
