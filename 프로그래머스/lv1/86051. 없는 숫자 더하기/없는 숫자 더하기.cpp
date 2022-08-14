#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<int> original = {1,2,3,4,5,6,7,8,9,0};
    
    for(auto i : numbers){
        for(int j = 0; j < original.size(); ++j){
            if(i == original[j]){
                original.erase(original.begin()+j);
                break;
            }
            
            
        }
    }
    
    for(auto i : original){
        answer += i; 
    }
    
    
    
    return answer;
}