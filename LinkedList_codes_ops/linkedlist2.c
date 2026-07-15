#include<stdio.h>
#include<stdlib.h>


struct listNode{
    int data ;
    struct listNode *next;
};
struct listNode *add(struct listNode *head,int el){

    struct listNode *temp = (struct listNode*)malloc(sizeof(struct listNode));
    temp -> data = el;
    temp -> next = NULL;
    if(head == NULL){
        return temp;
    }
    struct listNode *curr = head;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    curr->next = temp;
    return head;

}
void display(struct listNode *head){

    struct listNode *temp = head;
    while (temp != NULL){
        printf("%d ->",temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
    return;

}
void printaltnode(struct listNode *head){

    struct listNode *dummy = (struct listNode*)malloc(sizeof(struct listNode));
    dummy -> data = 0;// assuming any value
    dummy -> next = head;
    struct listNode *temp = dummy;
    while (dummy != NULL && dummy -> next != NULL && dummy -> next -> next != NULL ){
        dummy = dummy -> next -> next;
        printf("%d ",dummy->data);
    }
    printf("NULL");
}
int main(){

    struct listNode *head = (struct listNode * )malloc(sizeof(struct listNode));
    head = NULL;
    int choice;
    while(1){

        printf("-----MENU-----\n1.Add\n2.Print alternate nodes\n3.Display\n4.Exit\n");
        printf("Enter choice:\n");
        scanf("%d",&choice);
        getchar();

        switch(choice){
            
            case 1:{
                int d;
                printf("Input element to add:");
                scanf("%d",&d);
                getchar();
                head = add(head,d);
                printf("Added successfully\n");
                break;
            }
            case 2:{
                printaltnode(head);
                break;
            }
            case 3:{
                display(head);
                break;
            }
            case 4:{
                exit(1);
                break;
            }
            default:{
                printf("Invalid input.");
            }

        }
    }
    return 0;
}

