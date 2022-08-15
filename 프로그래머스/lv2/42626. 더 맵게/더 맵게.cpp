#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> a;
    
    for(auto i : scoville){
        a.push(i);
    }
    
    
    while(true){
        if(a.size() == 1 && a.top() < K){
            answer = -1;
            break;
        } 
        if(a.top() >= K) break;
        else{
            int temp = a.top();
            a.pop();
            a.push(a.top()*2 + temp);
            a.pop();
            ++answer;
        }
    }
    
    
    
    return answer;
}