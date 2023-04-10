#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int start = 0;
    int end = 0;
    int sum = sequence[0];
    int len = 1000001;
    
    while(end <= sequence.size()-1){
        if(sum > k){
            sum -= sequence[start];
            start += 1;
            if(start > end){
                end = start;
            }
        }
        else if(sum < k){
            end += 1;
            sum += sequence[end];
        }
        else{
            if(len > end-start+1){
                len = end - start + 1;
                answer.clear();
                answer.push_back(start);
                answer.push_back(end);
            }
            end += 1;
            sum += sequence[end];
        }
    }
    
    return answer;
}