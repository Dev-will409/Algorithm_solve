#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int inDegree[32001] = {0,};
vector<int> arr[32001];
queue<int> q;

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a].push_back(b);
        inDegree[b] += 1;
    }
    for (int i = 1; i <= n; ++i) {
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << q.front() << " ";
        int s = int(arr[q.front()].size());
        for (int j = 0; j < s; ++j) {
            int t = arr[q.front()][j];
            inDegree[t] -= 1;
            if(inDegree[t] == 0) q.push(t);
        }
        q.pop();
    }



    return 0;
}
