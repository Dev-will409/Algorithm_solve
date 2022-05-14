#include <iostream>
#include "algorithm"

using namespace std;

void change(int a[][4], int j)
{
    int temp1 = a[j][0];
    a[j][0] = a[j+1][0];
    a[j+1][0] = temp1;
    int temp2 = a[j][1];
    a[j][1] = a[j+1][1];
    a[j+1][1] = temp2;
    int temp3 = a[j][2];
    a[j][2] = a[j+1][2];
    a[j+1][2] = temp3;
    int temp4 = a[j][3];
    a[j][3] = a[j+1][3];
    a[j+1][3] = temp4;
}

int main() {
    int participant = 0;
    int score_count_time[10000][4] = {0,};
    int max = 0;
    cin >> participant;



    for (int i = 0; i < participant; ++i) {
        cin >> score_count_time[i][0] >> score_count_time[i][1] >> score_count_time[i][2];
        score_count_time[i][3] = i+1;
    }

    for (int i = 0; i < participant-1; ++i) {
        for (int j = 0; j < participant-i - 1; ++j) {
            if(score_count_time[j][0] < score_count_time[j+1][0]){
                change(score_count_time, j);
            }
        }
    }
    for (int i = 0; i < participant-1; ++i) {
        for (int j = 0; j < participant-i - 1; ++j) {
            if(score_count_time[j][0] == score_count_time[j+1][0] &&score_count_time[j][1] > score_count_time[j+1][1]){
                change(score_count_time, j);
            }
        }
    }
    for (int i = 0; i < participant-1; ++i) {
        for (int j = 0; j < participant-i - 1; ++j) {
            if(score_count_time[j][0] == score_count_time[j+1][0] && score_count_time[j][1] == score_count_time[j+1][1] && score_count_time[j][2] > score_count_time[j+1][2]){
                change(score_count_time, j);
            }
        }
    }


    cout << score_count_time[0][3] << endl;


    return 0;
}
