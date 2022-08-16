#include <bits/stdc++.h>

using namespace std;

vector<int> a;
   
bool comp(const string& a, const string&b){
    return a + b>b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> a;
    for(auto i : numbers){
        a.push_back(to_string(i));
    }
    
    sort(a.begin(),a.end(),comp);
    
    for(auto i: a){
        answer += i;
    }
    if(answer[0] == '0') return "0";
    
    return answer;
}