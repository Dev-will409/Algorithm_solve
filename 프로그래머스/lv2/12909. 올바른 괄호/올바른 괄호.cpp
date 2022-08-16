#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    vector<char> left;

    for(auto i : s){
        if(i == '('){
            left.push_back(i);
        }
        else{
            if(!left.empty()){
                left.pop_back();
            } 
            else{
                answer = false;
                break;
            }
        }
    }
    
    if(!left.empty()) answer = false;

    return answer;
}