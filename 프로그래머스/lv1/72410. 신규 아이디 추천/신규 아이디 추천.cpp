#include <string>
#include <vector>
#include <iostream>

using namespace std;

int smallA = 97;
int smallZ = 122;
int capitalA = 65;
int capitalZ = 90;
int char_num_zero = 48; 


string solution(string new_id) {
    string answer = "";
    
    for(int i = 0; i < new_id.size(); ++i){
        if(int(new_id[i]) >= 65 && int(new_id[i]) <= 90){
            new_id[i] += 32;
        }
    }
    
    for(int i = 0; i < new_id.size(); ++i){
        if((int(new_id[i]) >= 97 && int(new_id[i]) <= 122) || 
           (int(new_id[i]) >= 48 && int(new_id[i]) <= 57) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            continue;
        }
        else{
            new_id.erase(i,1);
            --i;
        }
    }
    
    for(int i = 0; i < new_id.size(); ++i){
        if(i != 0 && new_id[i] == '.' && new_id[i-1] == '.'){
            new_id.erase(i,1);
            --i;
        }
    }
    
    if(new_id[0] == '.'){
        new_id.erase(0,1);
    }
    if(new_id[new_id.size()-1] == '.'){
        new_id.erase(new_id.size()-1,1);
    }
    
    if(new_id.empty()){
        new_id = "a";
    }
    
    if(new_id.size() >= 16){
        new_id.erase(15, new_id.size() - 15);
    }
    
    if(new_id[new_id.size()-1] == '.'){
        new_id.erase(new_id.size()-1,1);
    }
    
    if(new_id.size() == 1){
        string temp = new_id;
        new_id += temp + temp;
    }
    else if(new_id.size() == 2){
        new_id.append(new_id,1,1);
    }
    
    answer = new_id;
    
    for(auto i : new_id){
        cout << i;
    }
    
    
    
    
    return answer;
}