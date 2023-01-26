#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int inDegree[32001] = {0,};

vector<int> arr[32001];
queue<int> q;

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int a,b;
        scanf("%d %d", &a, &b);
        inDegree[b] += 1;
        arr[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()){
        printf("%d ", q.front());
        for (int i = 0; i < arr[q.front()].size(); ++i) {
            inDegree[arr[q.front()][i]] -= 1;
            if (inDegree[arr[q.front()][i]] == 0){
                q.push(arr[q.front()][i]);
            }
        }
        q.pop();
    }


    return 0;
}
