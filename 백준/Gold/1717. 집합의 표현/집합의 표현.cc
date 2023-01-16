#include <iostream>

using namespace std;

int arr[1000001] = {0,};


int find(int a){
    if(arr[a] == a) return a;
    else return arr[a] = find(arr[a]);
}

void merge(int a, int b){
    int root_a = find(a);
    int root_b = find(b);

    arr[root_a] = root_b;
}

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i <= n; ++i) {
        arr[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int flag;
        scanf("%d", &flag);

        if(flag == 0){
            int a, b;
            scanf("%d %d",&a, &b);
            merge(a,b);
        }
        else{
            int a, b;
            scanf("%d %d",&a, &b);
            
            if(find(a) == find(b)) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
