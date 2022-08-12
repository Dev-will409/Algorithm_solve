#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int match = 0;
    int n = 7;
    int zero = 0;
    
    for(auto i : lottos){
        if(i == 0) ++zero;
        for(auto j : win_nums){
            if(i == j){
                ++match;
            }
        }
    }
    
    int top;
    int bottom;
    match == 0 ? bottom = n - match - 1 : bottom = n-match;
    if(match == 0){
        if(zero == 0){
            top = 6;
        }
        else{
            top = n - zero;
        }
    }
    else{
        top = n - match - zero;
    }
    
    
    answer.push_back(top);
    answer.push_back(bottom);
    
    
    
    
    return answer;
}