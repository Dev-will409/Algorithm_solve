#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct JOB{
    int start;
    int time;
    
    bool operator< (const JOB& job) const{
        return time > job.time;
    }
};

priority_queue<JOB> pq;

bool cmp(vector<int> a, vector<int> b){
    return a[0] > b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end(),cmp);
    
    int time = 0;
    int cost = 0;
    int len = jobs.size();
    
    JOB now;
    now.start = jobs[jobs.size()-1][0];
    now.time = jobs[jobs.size()-1][1];
    
    jobs.pop_back();
    
    cost += now.time;
    time += now.start + now.time;
    
    while(!jobs.empty() || !pq.empty()){
        bool flag = false;
        for (int i = jobs.size()-1; i >= 0; --i){
            if(jobs[i][0] < time){
                JOB temp;
                temp.start = jobs[i][0];
                temp.time = jobs[i][1];
                pq.push(temp);
                jobs.pop_back();
                flag = true;
            }
            else{
                if(flag || !pq.empty()) break;
                else{
                    JOB temp;
                    temp.start = jobs[i][0];
                    temp.time = jobs[i][1];
                    time = jobs[i][0];
                    pq.push(temp);
                    jobs.pop_back();
                    flag = true;
                }
            }
        }
        
        
        if(!pq.empty()){
            time += pq.top().time;
            cost += time - pq.top().start;
            pq.pop();
        }
        
    }
    
    answer = cost/len;
    
    return answer;
}