#include <iostream>

int arr[100001] = {0,};

int main() {
    int n, s;

    scanf("%d %d", &n, &s);

    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    int start, end;
    start = 0;
    end = 0;
    int total = arr[start];
    int min_len = 100002;
    while (start < n){
        if(total >= s){
            if(end-start+1 < min_len){
                min_len = end-start+1;
            }
            total -= arr[start];
            if(start == end) end += 1;
            start += 1;
        }
        else{
            if(end == n-1){
                total -= arr[start];
                start += 1;
            }
            else{
                end += 1;
                total += arr[end];
            }
        }
    }

    if(min_len == 100002) printf("0");
    else printf("%d", min_len);

    return 0;
}
