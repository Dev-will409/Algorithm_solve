#include <iostream>


using namespace std;

int main() {
    int dir[6] = {0,};
    int length[6] = {0,};
    int k = 0;

    int width = 0;
    int height = 0;

    cin >> k;

    for (int i = 0; i < 6; ++i) {
        cin >> dir[i] >> length[i];
        if(dir[i] == 1 || dir[i] == 2){
            if(width < length[i]) width = length[i];
        }
        if(dir[i] == 3 || dir[i] == 4){
            if(height < length[i]) height = length[i];
        }
    }

    int big_square = height * width;
    int small_square = 0;


    for (int i = 0; i < 6; ++i) {
        if(length[i%6] == width && length[(i+1)%6] == height){
            small_square = length[(i+3)%6] *length[(i+4)%6];
        }
        if(length[i%6] == height && length[(i+1)%6] == width){
            small_square = length[(i+3)%6] *length[(i+4)%6];
        }
    }

    cout << (big_square - small_square)*k << endl;





    return 0;
}