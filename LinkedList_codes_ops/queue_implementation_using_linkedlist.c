#include<stdio.h>
#include<stdlib.h>
typedef struct listNode{
    int data;
    struct listNode *next;
}ll;
ll * front = NULL;
ll * rear = NULL;
void enqueue(int el){

    ll * newNode = (ll *)malloc(sizeof(ll));
    newNode -> data = el;
    newNode -> next = NULL;
    if(front == NULL && rear == NULL){
        rear = newNode;
        rear -> next = NULL;
    }
    else{
        rear -> next = newNode;
        if(front == NULL){
            front = rear;
        }
        rear = rear -> next;
        rear -> next = NULL;
    }
}
void dequeue(){
    if(front == rear){
        return ;
    }
    ll * t = front;
    front = front -> next;
    printf("The integer popped out is :%d\n",t-> data);
    free(t);
}
void print(){
    ll * s = front;
    while(s!= NULL){
        printf("%d ",s-> data);
        s = s -> next;
    }
}
void peek(){
    printf("The first elements data:%d\n",front-> data);
}
int main(){
    ll * queue = NULL;

    printf("MENU\n");
    printf("1.Queue add\n");
    printf("2.Queue remove\n");
    printf("3.Print queue elements\n");
    printf("4.Peek\n");
    printf("5.EXIT\n");

    while(1){

        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Input element:");
                int k;
                scanf("%d",&k);getchar();
                enqueue(k);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                print(queue);
                break;
            }
            case 4:{
                peek();break;
            }
            case 5:{
                exit(0);
            }
            default:{
                printf("Invalid input\n");
            }
        }
    }
    return 0;
}                    
