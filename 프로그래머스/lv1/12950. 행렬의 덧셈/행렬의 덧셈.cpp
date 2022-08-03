#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    vector<int> a;
    for(int i = 0; i < arr1.size(); ++i){
        for(int j = 0; j < arr1[i].size(); ++j){
            a.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(a);
        a.clear();
    }
    
    
    return answer;
}