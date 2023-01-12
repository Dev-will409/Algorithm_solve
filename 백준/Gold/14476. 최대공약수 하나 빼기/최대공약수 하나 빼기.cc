#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(a%b == 0){
        return b;
    }
    return gcd(b, a%b);
}

int arr[1000001] = {0,};
int lgcd[1000001] = {0,};
int rgcd[1000001] = {0,};

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",arr + i);
    }

    lgcd[0] = arr[0];
    for (int i = 1; i < n; ++i) {
         lgcd[i] = gcd(lgcd[i-1], arr[i]);
    }

    rgcd[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; --i) {
        rgcd[i] = gcd(rgcd[i+1], arr[i]);
    }
    
    
    int mgcd = 1;
    int out = 0;
    int tg = 0;
    for (int i = 0; i < n; ++i) {
        if(i == 0) tg = rgcd[1];
        else if(i == n-1) tg = lgcd[n-2];
        else tg = gcd(lgcd[i-1], rgcd[i+1]);
        if(tg > mgcd){
            mgcd = tg;
            out = arr[i];
        }

    }
    if(out % mgcd == 0) cout << -1 << endl;
    else cout << mgcd << " " << out << endl;

    return 0;
}
