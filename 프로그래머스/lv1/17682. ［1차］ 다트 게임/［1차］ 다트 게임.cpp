#include <bits/stdc++.h>

using namespace std;

int Dou(int a){
    return a*a;
}

int Tri(int a){
    return a*a*a;
}



int solution(string dartResult) {
    int answer = 0;
    
    vector<int> point;
    
    for(int i = 0; i < dartResult.size(); ++i){
        if(dartResult[i] == 'S'){
            
        }
        else if(dartResult[i] == 'D'){
            point[point.size()-1] = Dou(point[point.size()-1]);
        }
        else if(dartResult[i] == 'T'){
            point[point.size()-1] = Tri(point[point.size()-1]);
        }
        else if(dartResult[i] == '*'){
            if(point.size() < 2){
                point[point.size()-1] = point[point.size()-1]*2;
            }
            else{
                point[point.size()-1] = point[point.size()-1]*2;
                point[point.size()-2] = point[point.size()-2]*2;   
            }
        }
        else if(dartResult[i] == '#'){
            point[point.size()-1] = point[point.size()-1]*-1;
        }
        else if(dartResult[i] == '1'){
            if(dartResult[i+1] == '0'){
                ++i;
                point.push_back(10);
            }
            else{
                point.push_back(int(dartResult[i]-48));
            }
        }
        else{
            point.push_back(int(dartResult[i]-48));
        }
    }
    
    for(auto i : point){
        answer += i;
    }
                            
    return answer;
}