#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int,int>> a;
    
    for(int i = 0; i < priorities.size();++i){
        a.push(make_pair(priorities[i],i));
    }
    
    int cnt = 0;
    while(!a.empty()){
        bool check = false;
        int temp = a.front().first;
        for(int i = 0; i < a.size(); ++i){
            int tmp = a.front().first;
            if(tmp > temp) check = true;
            a.push(a.front());
            a.pop();
        }
        
        if(check){
            a.push(a.front());
            a.pop();
        }
        else{
            if(a.front().second == location){
                answer = cnt + 1;
                break;
            }
            else{  
                a.pop();
                cnt += 1;
            }
        }
    }
    
    answer = cnt+1;
    
    return answer;
}