#include<stdio.h>
#include<stdlib.h>
#include <time.h>

struct listNode{
    int data;
    struct listNode *next;
};
// addition of node in descending order

struct listNode *addListNodeSorted(struct listNode *start, int elem){
    struct listNode *temp = (struct listNode *)malloc(sizeof(struct listNode));
    struct listNode *dum = start;

    temp->data = elem;
    temp->next = NULL;

    if(start == NULL || start-> data < elem){
        temp->next = start;
        start = temp;
        return start;
    }

    while(dum->next != NULL && dum ->next->data > elem){
        dum = dum ->next;
    }

    temp ->next = dum ->next ;
    dum ->next = temp;
    return start;
}
struct listNode *sort(struct listNode *start){

    

}

void display(struct listNode *start){

    struct listNode *dummy;
    dummy = start;
    while(dummy != NULL){
        printf("%d->",dummy->data);
        dummy = dummy ->next;
    }
    printf("NULL\n");
}


int main(){
    
    printf("MENU\n");
    printf("1. Insert element\n");
    printf("8. Sort all the nodes in descending order again\n");
    printf("10. Exit\n");
    struct listNode *head = NULL;

    while(1){
        int choice;
        scanf("%d",&choice);
        switch(choice) {

            case 1:{
                int e;
                printf("Input element to insert\n");
                scanf("%d",&e);
                getchar();
            
                head = addListNodeSorted(head, e);
                break;
            }
            case 3:{
                display(head);
                break;
            }
            case 8:{
                head = sort(head);
                break;
            }
            case 10:{
                exit(1);
                break;
            }
            default:{
                printf("Input valid integer\n");
            }
        }
    }
    return 0;

}