#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;

struct NUM{
    int count;
    int number;
};

bool compare(const NUM &a, const NUM &b){
    if(a.count == b.count) return a.number < b.number;
    return a.count > b.count;
}

void Average(const vector<int> &numbers){
    int sum = 0;
    for (auto i : numbers){
        sum += i;
    }

    double avg = sum/double(numbers.size());

    cout << fixed;
    cout.precision(0);
    if(avg < 0 && avg >= -0.5) cout << 0 << endl;
    else cout << avg << endl;
}

void Median(const vector<int> &numbers){
    int i = 0;
    while (i < numbers.size()/2){
        ++i;
    }
    cout << numbers[i] << endl;
}

void Mode(const vector<int> &numbers){

    NUM arr_num[8001] = {{0,0}, };

    for (auto i : numbers) {
        arr_num[i+4000].number = i;
        ++arr_num[i + 4000].count;
    }

    sort(arr_num, arr_num+8001, compare);

    if(arr_num[0].count == arr_num[1].count) cout << arr_num[1].number << endl;
    else cout << arr_num[0].number << endl;
}

void Range(const vector<int> &numbers){
    cout <<  *(numbers.end() - 1) - *numbers.begin() << endl;
}

int main() {
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        num.push_back(a);
    }

    sort(num.begin(), num.end());

    Average(num);
    Median(num);
    Mode(num);
    Range(num);


    return 0;
}
