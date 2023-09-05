#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int last = -1;
    
    sort(targets.begin(), targets.end(),comp);
    
    for (int i = 0; i < targets.size(); ++i){
        if(targets[i][0] >= last){
            last = targets[i][1];
            answer += 1;
        }
        else{
        }
    }
    
    return answer;
}