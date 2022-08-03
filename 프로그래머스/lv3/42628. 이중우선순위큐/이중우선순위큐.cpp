#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> a;
    
    for(auto i : operations){
        if(i[0] == 'I'){
            int temp = stoi(i.substr(2,i.size()-2));
            a.push_back(temp);
        }
        else{
            if(a.empty()){
                continue;
            }
            else{
                if(i[2] == '-'){
                    a.erase(min_element(a.begin(), a.end()));
                }
                else{
                    a.erase(max_element(a.begin(), a.end()));
                }   
            }
        }
    }
    
    
    if(a.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(*max_element(a.begin(), a.end()));
        answer.push_back(*min_element(a.begin(), a.end()));
    }
    
    
    return answer;
}