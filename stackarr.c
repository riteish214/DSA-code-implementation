#define MAX 100
int stack[MAX], top = -1;

void push(int val) {
    if (top >= MAX - 1) printf("Stack Overflow\n");
    else stack[++top] = val;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
