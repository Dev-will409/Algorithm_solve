#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int j = 1;
    int i = brown/2 - j;
    while(j + 2 <= i){
        if(j * (i-2) == yellow){
            answer.push_back(i);
            answer.push_back(j+2);
            break;
        }
        j++;
        i--;
    }    
    
    
    return answer;
}