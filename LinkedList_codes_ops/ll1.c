#include<stdio.h>
#include<stdlib.h>
typedef struct poly_node {
    int coef; // stores coefficient 
    int expon; // stores exponenet
    struct poly_node * next;
}polynode;

polynode * 
void printList(struct listNode *start){

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
    printf("2. Delete element\n");
    printf("3. SEARCH Element in the LL\n");
    printf("4. Print Elementsin the LL\n");
    printf("5. Exit\n");
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
            case 4:{
                printList(head); 
                break;
            }
            case 3:{
                int sl;
                printf("Input element to search\n");
                scanf("%d",&sl);
                getchar();
                int c = isPresentListNodeSorted(head,sl);
                break;
            }
            case 2:{
                int dl;
                printf("Input element to delete\n");
                scanf("%d",&dl);
                getchar();
                head = deleteListNodeSorted(head,dl);
                break;
            }
            case 5:{
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