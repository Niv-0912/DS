#include <stdio.h>
#define N 5

int f = -1;
int r = -1;

struct Priority_Queue {
    int data;
    int priority;
};

struct Priority_Queue pq[N];

void enqueue(int x, int y) {
    if (r == N - 1) { 
        printf("Overflow\n");
        return;
    }
    
    r++; 
    pq[r].data = x;
    pq[r].priority = y;
    
    if (f == -1) {
        f = 0;
    }
}

void dequeue() { 
    if (r == -1 && f == -1) {
        printf("Underflow\n");
    } 
    else {
        if (f == r) {
            printf("Deleted data:%d || Priority is : %d\n", pq[r].data, pq[r].priority);
            r = f = -1;
        } 
        else {
            int max_index = f;
            int i;
            
            for (i = f + 1; i <= r; i++) { 
                if (pq[i].priority > pq[max_index].priority) {
                    max_index = i;
                }
            }
            printf("Deleted data:%d || Priority is : %d\n", pq[max_index].data, pq[max_index].priority);
            
            
            for (i = max_index; i < r; i++) {
                pq[i] = pq[i + 1];
            }
            r--;
        }
    }
}

void display() {
    int i;
    if (f == -1) {
        printf("Underflow\n");
        return;
    }
    printf("\nPriority queue is: ");
    
    for (i = f; i <= r; i++) { 
        printf("{%d %d} ", pq[i].data, pq[i].priority);
    }
    printf("\n");
}

void main() { 
    int choice, x, y;
    
    while (1) {
        printf("\nEnter 1 for Enqueue\nEnter 2 for Dequeue\nEnter 3 for Display\nEnter 4 for Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break; 
        
        switch (choice) {
            case 1:
                printf("Enter your data: ");
                scanf("%d", &x);
                printf("Enter your priority: ");
                scanf("%d", &y);
                enqueue(x, y);
                break; 
                
            case 2:
                dequeue();
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                return 0;
                
            default:
                printf("Enter a valid choice\n");
                break;
        }
    }
    
}
