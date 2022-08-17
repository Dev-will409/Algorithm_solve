#include <bits/stdc++.h>

using namespace std;

vector<char> num;
vector<char> a;
set<int> s;

void dfs(int depth){
    if(depth == num.size()){
        string k = "";
        for(int i = 0; i < a.size(); ++i){
            k += a[i];
        }
        int l = stoi(k);
        s.insert(l);
        return;
    }
    else if(depth == 0){
    }
    else{
        string k = "";
        for(int i = 0; i < a.size(); ++i){
            k += a[i];
        }
        int l = stoi(k);
        s.insert(l);
    }
    for(int i = 0; i < num.size(); ++i){
        char temp = num[i];
        if(temp == 'a') continue;
        a.push_back(temp);
        num[i] = 'a';
        dfs(depth+1);
        a.pop_back();
        num[i] = temp;
    }
}

int solution(string numbers) {
    int answer = 0;
    
    for(auto i : numbers){
        num.push_back(i);
    }
    
    dfs(0);
    
    for(auto i : s){
        cout << i << " ";
    }
    
    for(auto i : s){
        bool check = false;
        for(int j = 2; j <= sqrt(i); ++j){
            if(i%j == 0){
                check = true;
                break;
            }
        }
        if(i <= 1) continue;
        if(!check) answer += 1;
    }
    
    return answer;
}