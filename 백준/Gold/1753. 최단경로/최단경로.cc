#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge{
    int end;
    int cost;

    bool operator<(const edge& b) const {
        return cost > b.cost;
    }
};

const int INF = 1987654321;

vector<edge> arr[20001];
int d[20001] = {0,};

int main() {
    int v,e;

    cin >> v >> e;

    for (int i = 0; i <= v; ++i) {
        d[i] = INF;
    }

    int start_pos;
    cin >> start_pos;
    arr[0].push_back({start_pos,0});

    for (int i = 0; i < e; ++i) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        arr[start].push_back({end, cost});
    }

    priority_queue<edge> q;

    q.push(arr[0][0]);
    d[start_pos] = 0;

    while(!q.empty()){
        edge now = q.top();
        q.pop();

        int now_vertex = now.end;
        int now_cost = now.cost;

        int sz = arr[now_vertex].size();

        for (int i = 0; i < sz; ++i) {
            edge next = arr[now_vertex][i];

            int next_vertex = next.end;
            int next_cost = next.cost;

            if(d[next_vertex] > d[now_vertex] + next_cost){
                d[next_vertex] = d[now_vertex] + next_cost;
                q.push({next.end, d[next.end]});
            }
        }
    }

    for (int i = 1; i <= v; ++i) {
        if(d[i] == INF) printf("INF\n");
        else printf("%d\n",d[i]);
    }

    return 0;
}
