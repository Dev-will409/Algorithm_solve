#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int mat[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,0,11}};
    
    int lpx = 3;
    int lpy = 0;
    int rpx = 3;
    int rpy = 2;
    
    for(auto num : numbers){
        int ldis =0;
        int rdis =0;
        int numposx = 0;
        int numposy = 0;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 3; ++j){
                if(mat[i][j] == num){
                    numposx = i;
                    numposy = j;
                }
            }
        }
        if(numposy == 0){
            lpx = numposx;
            lpy = numposy;
            answer += "L";
        }
        else if(numposy == 2){
            rpx = numposx;
            rpy = numposy;
            answer += "R";
        }
        else{
            ldis = abs(numposx - lpx) + abs(numposy - lpy);
            rdis = abs(numposx - rpx) + abs(numposy - rpy);
            if(ldis == rdis){
                if(hand == "left"){
                    lpx = numposx;
                    lpy = numposy;
                    answer += "L";
                }
                else{
                    rpx = numposx;
                    rpy = numposy;
                    answer += "R";
                }
            }
            else if(ldis > rdis){
                rpx = numposx;
                rpy = numposy;
                answer += "R";
            }
            else{
                lpx = numposx;
                lpy = numposy;
                answer += "L";
            }
        }
        
        
    }
    
    
    return answer;
}