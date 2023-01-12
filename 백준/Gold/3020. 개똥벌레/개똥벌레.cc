#include <iostream>
#include "vector"

using namespace std;

int cave[200000] = {0,};
int up[500001] = {0,};
int down[500001] = {0,};
int main() {
    int n,h;
    cin >> n >> h;

    for (int i = 0; i < n; ++i) {
        scanf("%d",cave + i);
        if(i&1){
            up[cave[i]] += 1;
        }
        else{
            down[cave[i]] += 1;
        }
    }


    for (int i = h-1; i > 0 ; --i) {
        up[i] += up[i+1];
    }
    for (int i = h-1; i > 0 ; --i) {
        down[i] += down[i+1];
    }

    int ans = 0;
    int m = 999999;

    for (int i = 1; i <= h; ++i) {
        int t = up[i] + down[h-i+1];
        if(m > t){
            m = t;
            ans = 0;
        }
        if(m == t) ans += 1;
    }

    cout << m << " " << ans << endl;
    
    return 0;
}
