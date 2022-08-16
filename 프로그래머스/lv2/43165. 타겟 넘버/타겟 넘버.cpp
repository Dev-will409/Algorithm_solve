#include <string>
#include <vector>

using namespace std;

vector<int> a;
int answer = 0;

void dfs(int depth, int max_depth, vector<int> numbers, int target){
    if(depth == max_depth){
        int sum = 0;
        for(auto i : a){
            sum += i;
        }
        if(sum == target){
            answer += 1;
        }
        return;
    }
    a.push_back(numbers[depth]);
    dfs(depth+1, max_depth, numbers, target);
    a.pop_back();
    a.push_back(numbers[depth]*-1);
    dfs(depth+1, max_depth, numbers, target);
    a.pop_back();
}


int solution(vector<int> numbers, int target) {
    
    dfs(0, numbers.size(), numbers, target);
    
    return answer;
}