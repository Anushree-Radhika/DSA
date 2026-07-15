#include<stdio.h>
#include<stdlib.h>


struct queue{
    int front,rear,capacity;
    int *el;
};
struct queue *initialize(struct queue *q,int size){
    q->front = 0;
    q->rear = 0;
    q->capacity = size;
    q->el = (int *)malloc(sizeof(int) * size);
    if(!q->el){
        return NULL;
    }
    return q;
}
int isQFull(struct queue *q){
    if(q->front == (q->rear + 1)%(q->capacity)){
        return 1;
    }
    return 0;
}
int isQEmpty(struct queue *q){
    if(q->front == q->rear ){
        return 1;
    }
    return 0;
}
int enqueue(struct queue *q,int val){
    if(isQFull(q)){
        return 0;
    }
    q->el[q->rear] = val;
    q->rear = (q->rear + 1) % q->capacity;
    return 1;
}
int dequeue(struct queue *q){
    if(isQEmpty(q)){
        return 0;
    }
    q->front = (q->front + 1)% q->capacity;
    return 1;
}

int main(){
    struct queue *q;

    int ss;
    printf("Enter the queue size:");
    scanf("%d",&ss);
    getchar();

    int choice;
    while (1) {

        printf("\n--- Queue Menu ---\n");
        printf("1. Initialize the queue\n");
        printf("2. Add elements to the queue\n");
        printf("3. Pop elements out of the queue\n");
        printf("4. Free integer stack\n");
        printf("5. Is Queue full\n");
        printf("6. Is Queue empty\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        if (choice == 0) break;

        if (choice == 1) {
            q = initialize(q,ss);
            if (q) printf("Queue initialized successfully.\n");
            else printf("Failed to initialize queue.\n");
        }

        else if (choice == 2) {
        int r;
        printf("Enter element to add: ");
        scanf("%d", &r); getchar();
        if (enqueue(q, r))
            printf("Integer %d is successfully added to the queue.\n", r);
        else
            printf("Queue is full, cannot add %d.\n", r);
        }

        else if (choice == 3) {
            int dp = q->el[q->front];
            if (dequeue(q))
                printf("Integer is successfully deleted from the stack.\n");
            else
                printf("Failed to remove the integer from the stack.\n");
        }
        else if (choice == 5) {
            if( isQFull(q) ){
                printf("Queue is full.\n");
            }
            else{
                printf("Queue is not full.\n");
            }
        }
        else if (choice == 6) {
            if( isQEmpty(q) ){
                printf("Queue is empty.\n");
            }
            else{
                printf("Queue is not empty.\n");
            }
        }
        else printf("Invalid choice.\n");
    }
    return 0;
}
