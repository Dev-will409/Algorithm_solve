#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    queue<long long> q1;
    queue<long long> q2;
    queue<long long> oq1;
    queue<long long> oq2;
    
    long long sum = 0;
    long long q1sum = 0;
    long long q2sum = 0;
    
    for (int i = 0; i < queue1.size(); ++i){
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        q1sum += queue1[i];
        q2sum += queue2[i];
        sum += (queue1[i] + queue2[i]);
    }
    if(sum %2 == 1) return -1;
    sum /= 2;
    
    oq1 =q1;
    oq2 = q2;
    
    while(!q1.empty() && !q2.empty()){
        if(q1sum > q2sum){
            answer += 1;
            q1sum -= q1.front();
            q2sum += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else if(q1sum < q2sum){
            answer += 1;
            q2sum -= q2.front();
            q1sum += q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        else{
            return answer;
        }
        if(answer > 600000) return -1;
        if(q1 == oq1 || q2 == oq1) return -1;
    }
    
    
    
    return -1;
}