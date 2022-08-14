#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> toy;
    
    for(int i = 0; i < moves.size(); ++i){
        for(int j = 0; j < board.size(); ++j){
            if(board[j][moves[i]-1] != 0){
                toy.push_back(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0;
                if(toy.size() > 1 && toy[toy.size()-1] == toy[toy.size()-2]){
                    toy.pop_back();
                    toy.pop_back();
                    answer += 2;
                }
                break;
            }
        }
    }
    
    
    
    return answer;
}