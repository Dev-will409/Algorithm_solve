#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e18;

struct edge{
    int end;
    int cost;
};

vector<edge> city[501];
long long d[501] = {0,};

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        city[start].push_back({end, cost});
    }

    fill(d, d+n+1, INF);

    d[1] = 0;

    for (int i = 0; i < n-1; ++i) {
        for (int j = 1; j <= n; ++j) {
            int len = city[j].size();
            for (int k = 0; k < len; ++k) {
                int next_end = city[j][k].end;
                int next_cost = city[j][k].cost;

                if(d[j] != INF && d[next_end] > d[j] + next_cost){
                    d[next_end] = d[j] + next_cost;
                }
            }
        }
    }

    for (int j = 1; j <= n; ++j) {
        int len = city[j].size();
        for (int k = 0; k < len; ++k) {
            int next_end = city[j][k].end;
            int next_cost = city[j][k].cost;

            if(d[j] != INF && d[next_end] > d[j] + next_cost){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if(d[i] == INF) printf("-1\n");
        else printf("%lld\n", d[i]);
    }

    return 0;
}
