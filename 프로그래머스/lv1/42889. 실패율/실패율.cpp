#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int user = stages.size();
    vector<double> fail;
    
    
    for(int j = 1; j <= N; ++j){
        double sum = 0;
        for(int i = 0; i < stages.size(); ++i){
            if(stages[i] == j){
                ++sum;
            }
        }
        if(user == 0){
            fail.push_back(0);
        }
        else{
            fail.push_back(sum/user);
        }
        user -= sum;
    }
    
    for(auto i : fail){
        cout << i<< " ";
    }
    cout << endl;
    
    for(int i = 0; i < N; ++i){
        double max = -1;
        int pos = 0;
        for(int j = 0; j < N; ++j){
            if(fail[j] > max){
                max = fail[j];
                pos = j;
            }
        }
        fail[pos] = -1;
        answer.push_back(pos+1);
    }
    
    
    
    return answer;
}