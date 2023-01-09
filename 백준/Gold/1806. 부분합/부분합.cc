#include <iostream>

using  namespace std;

int main() {
    int n, s;

    cin >> n >> s;

    int arr[100000] = {};
    int minn = 100000001;
    int start=0;
    int end = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int temp = arr[0];
    while (start < n){
        if(temp >= s){
            if(minn > (end-start+1)) minn = end-start+1;
            temp -= arr[start];
            if(start == end) end += 1;
            start += 1;
        }
        else{
            if(end == n-1){
                temp -= arr[start];
                start += 1;
            }
            else{
                end += 1;
                temp += arr[end];
            }
        }
    }

    if(minn == 100000001) cout << 0;
    else cout << minn;
    return 0;
}
