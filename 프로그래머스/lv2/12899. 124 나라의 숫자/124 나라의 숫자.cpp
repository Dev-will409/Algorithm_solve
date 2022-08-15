#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";
    
    
    string temp = "";
    while(n>0){
        if(n%3 == 0){
            temp += "4";    
            n /= 3;
            --n;
        }
        else if(n%3 == 1){
            temp += "1"; 
            n /= 3;
        }
        else{
            temp += "2"; 
            n /= 3;
        }
    }
    
    for(int i = temp.size()-1; i >= 0; --i){
        answer.append(temp, i,1);
    }
    
    return answer;
}