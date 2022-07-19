#include <iostream>


using namespace std;

int w[101][101][101] = {0,};

int W(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    else if (a > 20 || b > 20 || c > 20)
        return W(20, 20, 20);
    else if (a < b && b < c)
    {
        if (w[a][b][c] != 0) return w[a][b][c];
        else return w[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
    }
    else
    {
        if (w[a][b][c] != 0) return w[a][b][c];
        else return w[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
    }
}


int main() {
    while(true){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << W(a,b,c) << endl;
    }

    return 0;
}