#include <iostream>

using namespace std;

int tree[1000001] = {0,};

int main() {
    long long n, m;
    cin >> n >> m;
    int mt = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&tree[i]);
        mt = max(tree[i], mt);
    }

    int low = 0;
    int hi = mt;
    long long h = 0;

    while(low < hi){
        int mid = (low + hi)/2;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if(tree[i] >= mid) sum += (tree[i] - mid);
        }
        if(sum > m) {
            h = mid;
            low = mid + 1;
        }
        else if (sum < m){
            hi = mid;
        }
        else {
            h = mid;
            break;
        }
    }

    cout << h << endl;

    return 0;
}
