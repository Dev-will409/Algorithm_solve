#include <iostream>

using namespace std;

long long arr[1001][1001] = {0,};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < 1001; ++j) {
            for (int k = 0; k < 1001; ++k) {
                arr[j][k] = 0;
            }
        }
        int n, k;

        scanf("%d %d", &k, &n);
        arr[0][0] = 1;
        for (int l = 1; l <= n; ++l) {
            for (int j = 0; j <= l; ++j) {
                if(j == 0) arr[l][j] = 1;
                else{
                    arr[l][j] = arr[l-1][j] + arr[l-1][j-1];
                }
            }
        }

        printf("%lld\n",arr[n][k]);
    }




    return 0;
}
