#include <string>
#include <vector>

using namespace std;

int pairstr(string s){
    vector<char> a;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '(') a.push_back(s[i]);
        else {
            if(a.empty()) return 0;
            else a.pop_back();
        }
    }
    if(a.empty()) return 1;
    else return 0;
}

string rightstr(string s){
    if(s.empty()) return "";
    string u = "";
    string v = "";
    int r = 0;
    int l = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '(') l += 1;
        else r += 1;
        if(r == l){
            u = s.substr(0, i+1);
            v = s.substr(i+1, s.length());
            break;
        }
    }
    
    if(pairstr(u)){
        v = rightstr(v);
        return u + v;
    }
    
    else{
        string temp = "(";
        temp += rightstr(v);
        temp += ")";
        for(int i = 0; i < u.length(); ++i){
            if(i == 0 || i == u.length()-1) continue;
            if(u[i] == '(') temp += ")";
            else temp += '(';
        }
        return temp;
    }
    
    
}

string solution(string p) {
    string answer = "";
    if(pairstr(p)) answer = p;
    else answer = rightstr(p);
    return answer;
}