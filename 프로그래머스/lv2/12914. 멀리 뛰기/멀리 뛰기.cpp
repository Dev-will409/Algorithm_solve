#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int n) {
    
    vector<long long> num;
    
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);
    
    for(int i = 3; i <= n; ++i){
        num.push_back((num[i-1] + num[i-2])%1234567);
    }
    
    return num[n];
}