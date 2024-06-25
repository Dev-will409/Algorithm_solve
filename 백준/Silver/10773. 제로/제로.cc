#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stack[100'001] = { 0, };
int ptr = 0;
int sum = 0;

void push(int a) {
    stack[ptr++] = a;
    sum += a;
}

void pop() {
    ptr -= 1;
    sum -= stack[ptr];
}

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int n = 0;
        scanf("%d", &n);
        n == 0 ? pop() : push(n);
    }
    printf("%d\n", sum);
    return 0;
}