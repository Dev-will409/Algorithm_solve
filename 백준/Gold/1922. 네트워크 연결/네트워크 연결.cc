#include <iostream>
#include <algorithm>


using namespace std;

struct edge{
    int start;
    int end;
    int cost;
};

bool compare(edge a, edge b){
    return a.cost < b.cost;
}

edge arr[100001] = {0,};
int parent[1001] = {0,};

int find(int a){
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

bool merge(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    if(parent[root_a] == root_b) return true;
    parent[root_a] = root_b;
    return false;
}




int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        arr[i] = {start, end, cost};
    }
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }

    sort(arr, arr + m, compare);

    int edge_count = 0;
    int now_cost = 0;

    for (int i = 0; i < m; ++i) {
        if(merge(arr[i].start, arr[i].end) == false){
            now_cost += arr[i].cost;
            edge_count += 1;
        }

        if(edge_count == n-1){
            cout << now_cost << endl;
            break;
        }
    }




    return 0;
}
