#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    int mat1[17][17] = {0,};
    int mat2[17][17] = {0,};
    
    for(int i = 0; i < arr1.size(); ++i){
        for(int j = 1; j <= n; ++j){
            mat1[i][n-j] = arr1[i]%2;
            arr1[i] /= 2;
        }
    }
    
    for(int i = 0; i < arr2.size(); ++i){
        for(int j = 1; j <= n; ++j){
            mat2[i][n-j] = arr2[i]%2;
            arr2[i] /= 2;
        }
    }
    
    for(int i = 0; i < n; ++i){
        string temp = "";
        for(int j = 0; j < n; ++j){
            if(mat1[i][j] || mat2[i][j]){
                temp += "#";
            }
            else{
                temp += " ";
            }
        }
        answer.push_back(temp);
    }
    
    
    
    return answer;
}