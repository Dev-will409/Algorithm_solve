#include <iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<char> left;
    
    for (int i = 0; i < s.size(); ++i){
        if(!left.empty() && left[left.size()-1] == s[i]){
            left.pop_back();
        }
        else{
            left.push_back(s[i]);
        }
    }
    
    if(left.empty()){
        answer = 1;
    }
    else{
        answer = 0;
    }
    
    return answer;
}