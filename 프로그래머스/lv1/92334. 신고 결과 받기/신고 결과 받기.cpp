#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    // vector<vector<string>> list;
    // vector<int> reported_list;
    // vector<bool> stop_id_list;
    
    vector<vector<int>> list;
    vector<int> reported_list;
    vector<bool> stop_id_list;
    
    
    int id_size = id_list.size();
    
    for(int i = 0; i < id_size; ++i){
        vector<int> temp;
        for(int j = 0; j < id_size; ++j){
            temp.push_back(0);
        }
        list.push_back(temp);
        temp.clear();
    }
    
    for(int i = 0; i < id_size; ++i){
        reported_list.push_back(0);
        stop_id_list.push_back(false);
        answer.push_back(0);
    }
    
    
    for(auto i : report){
        for(int j = 0; j < i.size(); ++j){
            string a;
            string b;
            if(i[j] == ' '){
                a = i.substr(0,j);
                b = i.substr(j+1, i.size()-j);
                
                for(int k = 0; k < id_size; ++k){
                    if(a == id_list[k]){
                        for(int l = 0; l < id_size; ++l){
                            if(b == id_list[l]){
                                ++list[k][l];
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    
    
    
    for(int i = 0; i < list.size(); ++i){
        for(int j = 0; j < id_size; ++j){
            if(list[i][j] != 0){
                ++reported_list[j];
            }
        }
    }
        
    for(int i = 0; i < id_size; ++i){
        if(reported_list[i] >= k){
            stop_id_list[i] = true;
        }
    }
        
        
    for(int i =0 ; i < id_size; ++i){
        for(int j = 0; j < id_size; ++j){
            if(stop_id_list[j] && list[i][j]){
                ++answer[i];
            }
        }
    }
        
    
    
        
    
    return answer;
}