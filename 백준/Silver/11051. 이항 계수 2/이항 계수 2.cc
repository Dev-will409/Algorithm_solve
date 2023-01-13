#include <iostream>

using namespace std;

int arr[1001][1001] = {0,};

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    arr[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if(j == 0) arr[i][j] = 1;
            else{
                arr[i][j] = (arr[i-1][j] + arr[i-1][j-1])%10007;
            }
        }
    }

    cout << arr[n][k] << endl;


    return 0;
}
