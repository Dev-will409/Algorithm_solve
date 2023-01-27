#include <iostream>
#include "vector"
#include "queue"

#define INF 2e9

using namespace std;

struct edge{
    int end;
    int cost;

    bool operator<(const edge &b) const {
        return cost > b.cost;
    }
};

vector<edge> adj[20001];
int dist[20001] = {0,};


int main() {
    int v,e;
    scanf("%d %d", &v, &e);

    for (int i = 0; i <= v; ++i) {
        dist[i] = INF;
    }

    int start_node;
    scanf("%d", &start_node);

    for (int i = 0; i < e; ++i) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        adj[start].push_back({end, cost});
    }

    priority_queue<edge> q;

    q.push({start_node, 0});
    dist[start_node] = 0;

    while (!q.empty()){
        edge now = q.top();
        q.pop();

        int s = adj[now.end].size();
        for (int i = 0; i < s; ++i) {
            edge next = adj[now.end][i];
            if(dist[next.end] > dist[now.end] + next.cost){
                dist[next.end] = dist[now.end] + next.cost;
                q.push({next.end, dist[next.end]});
            }
        }
    }

    for (int i = 1; i <= v; ++i) {
        if(dist[i] == INF) printf("INF\n");
        else printf("%d\n", dist[i]);
    }

    return 0;
}
