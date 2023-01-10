#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

#define MAX 1000001
int N, M, K;
int two = 1, n = 0;
long long tree[MAX * 4] = { 0, };

int main() {
	cin >> N >> M >> K;
	
	while (N > two) {
		two *= 2;
		n++;
	}

	for (int i = 0; i < N; i++)
		cin >> tree[i + two];

	for (int i = two - 1; i > 0; i--) 
		tree[i] = tree[i * 2] + tree[i * 2 + 1];

	long long a, b, c;
	long long rst = 0;
	while (M > 0 || K > 0) {
		cin >> a >> b >> c;
		if (a == 1) {
			M--;
			long long interv = c - tree[two + b - 1];	
			for (long long i = two + b - 1; i > 0; i /= 2)
				tree[i] += interv;
		}
		else if (a == 2) {
			K--;
			rst = 0;
			long long l = two + b - 1;
			long long r = two + c - 1;

			while (l <= r) {
				if (l % 2 != 0){
					rst += tree[l];
					l++;			
				}

				if (r % 2 == 0){
					rst += tree[r];	
					r--;			
				}
				
				if (l == r)
					break;

				l /= 2;
				r /= 2;
			}
			cout << rst << endl;
		}
	}

	return 0;
}