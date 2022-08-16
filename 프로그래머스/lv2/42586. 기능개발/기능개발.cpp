#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> a;
    queue<int> spd;
    
    for(auto i : progresses){
        a.push(i);
    }
    
    for(auto i : speeds){
        spd.push(i);
    }
    
    while(!a.empty()){
        int count = 0;
        for(int i = 0; i < a.size(); ++i){
            int temp = a.front() + spd.front();
            a.pop();
            a.push(temp);
            spd.push(spd.front());
            spd.pop();
        } 
        while(a.front() >= 100 && !a.empty()){
            ++count;
            a.pop();
            spd.pop();
        }
        if(count) answer.push_back(count);
    }
    
    return answer;
}