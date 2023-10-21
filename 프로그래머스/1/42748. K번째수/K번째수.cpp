#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int q = 0; q < commands.size(); ++q){
        int i = commands[q][0];
        int j = commands[q][1];
        int k = commands[q][2];
        vector<int> temp;
        for (int w = i-1; w < j; ++w){
            temp.push_back(array[w]);
        }
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[k-1]);
    }
    return answer;
}