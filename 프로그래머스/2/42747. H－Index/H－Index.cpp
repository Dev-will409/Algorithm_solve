#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    int n = citations.size();
    int h = 0;
    
    for (int i = 0; i < n; ++i){
        h = max(min(citations[i], n-i),h);    
    }
    
    answer = h;
    
    return answer;
}