#include<stdio.h>
#include<stdlib.h>
struct listNode{
    int data;
    struct listNode *next;
};
struct listNode *intersection(struct listNode* head1,struct listNode* head2){

    struct listNode *temp1 = head1;
    struct listNode *temp2 = head2;
    struct listNode *temp3 ;
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    while(temp1 != NULL && temp2 != NULL){

        if(temp1 -> data < temp2 -> data){
            temp3 = temp1;
        }
        else if(temp1 -> data == temp2 -> data){
        //     temp3 -> next = temp1;
        //     temp1 = temp1 -> next;
        //     temp3 = temp3 -> next; 
        //     struct listNode *curr = (struct listNode *)malloc(sizeof(struct listNode));
        //     curr = temp2;
        //     temp3 -> next = curr;
        //     temp

        // }

    }

}