#include <bits/stdc++.h>

using namespace std;



int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> truck;
    for(auto i : truck_weights){
        truck.push(i);
    }
    queue<pair<int, int>> q;
    int time = 1;
    int total = truck_weights[0];
    q.push(make_pair(truck_weights[0],time));
    truck.pop();
    
        
    while(true){
        if(q.empty() && truck.empty()) break;
        time += 1;
        if(!q.empty() && time - q.front().second >= bridge_length) 
        {
            total -= q.front().first;
            q.pop();
        }
        if(!truck.empty() && truck.front() + total <= weight && q.size() < bridge_length) {
            q.push(make_pair(truck.front(),time));
            total += truck.front();
            truck.pop();
        }
    }
    answer = time;
    return answer;
}