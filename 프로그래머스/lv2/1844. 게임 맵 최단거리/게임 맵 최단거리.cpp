#include<bits/stdc++.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

bool CanGo(int x, int y, int n, int m, int maps[101][101], int step[101][101]){
    return x >= 0 && y >= 0 && x < n && y < m && maps[x][y] == 1 && step[x][y] == 0;
}

int step[101][101] = {0,};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    step[0][0] = 1;
    q.push(make_pair(0,0));
    int n = maps.size();
    int m = maps[0].size();
    // int ma[101][101] = {0,};
    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < m; ++j){
    //         ma[i][j] = maps[i][j];
    //     }
    // }
    
    while(!q.empty()){
        int x =  q.front().first;
        int y =  q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && maps[nx][ny] == 1 && step[nx][ny] == 0){
                step[nx][ny] = step[x][y] + 1;
                q.push(make_pair(nx, ny));  
            } 
        }
    }
    
    if(step[n-1][m-1]){
        answer = step[n-1][m-1];
    }
    else answer = -1;
    
    return answer;
}