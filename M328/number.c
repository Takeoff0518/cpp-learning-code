#include <stdio.h>

#define MAXN 100000

int stack[MAXN], top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    --top;
}

int topElement() {
    return stack[top];
}

int main() {
    int n, a[MAXN], ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        while (top != -1 && topElement() < a[i]) {
            pop();
            ++ans;
        }
        push(a[i]);
    }
    printf("%d\n", ans);
    return 0;
}

