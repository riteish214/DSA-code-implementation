#define MAX 100
int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if (rear >= MAX - 1) printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}
