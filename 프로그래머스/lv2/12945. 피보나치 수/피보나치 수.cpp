#include <string>
#include <vector>

using namespace std;

int fib[100001] = {0,};

int fibb(int n){
    if(n == 0) {fib[0] = 0; return 0;}
    if(n == 1) {fib[1] = 1; return 1;}
    if(fib[n] == 0) fib[n] = (fibb(n-1) + fibb(n-2))%1234567;
    return fib[n-2] + fib[n-1];
}

int solution(int n) {
    int answer = 0;
    answer = fibb(n)%1234567;
    return answer;
}