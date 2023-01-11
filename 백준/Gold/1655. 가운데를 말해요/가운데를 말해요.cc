#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;

    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d",&temp);
        if (max_heap.empty()) max_heap.push(temp);
        else{
            if(max_heap.size() > min_heap.size()){
                if(max_heap.top() > temp){
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                    max_heap.push(temp);
                }
                else min_heap.push(temp);
            }
            else{
                if(min_heap.top() < temp){
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                    min_heap.push(temp);
                }
                else max_heap.push(temp);
            }
        }
        if(i % 2 == 1){
            printf("%d\n",min(min_heap.top(), max_heap.top()));
        }
        else{
            printf("%d\n",max_heap.top());
        }

    }


    return 0;
}
