#include<stdio.h>

struct listNode {
    int data;
    struct listNode * next;
};
struct listNode *addListNode(struct listNode *start, int elem){

    struct listNode * temp = start;
    struct listNode * nw = (struct listNode *)malloc(sizeof(struct listNode));
    nw -> data = elem;
    if(temp == NULL){
        temp ->data = elem;
        start = temp;
        return start;
    }
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp ->next = nw;
    nw ->next = NULL;
    return start;
    
}
struct listNode *reverseList(struct listNode *start){

    if(start == NULL || start ->next == NULL){
        return start;
    }
    struct listNode *newHead = reverseList(start->next);
    start->next-> next = start;
    start ->next = NULL;
    return newHead;

}
struct listNode *subtractList(struct listNode *start1,struct listNode *start2){


}
struct listNode *addList(struct listNode *start1,struct listNode *start2){
    reverseList(start1);
    reverseList(start2);
    struct listNode * st = (struct listNode *)malloc(sizeof(struct listNode));
    struct listNode *temp1,*temp2 ;
    int carry = 0;struct listNode *head;

    while(temp1 != NULL && temp2 != NULL){

        st -> data = (temp1 -> data + temp2 -> data + carry)%10;
        carry = (temp1 -> data + temp2 -> data)/10;

        struct listNode * curr = (struct listNode *)malloc(sizeof(struct listNode));
        curr->data = 0;
        st->next = curr;
        st = curr;
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;

    }
    if(temp1 != NULL){
        st->next->data = (temp1->data + carry)%10;
        carry = (temp1->data + carry)/10;
        struct listNode * curr = (struct listNode *)malloc(sizeof(struct listNode));
        curr->data = 0;
        st->next = curr;
        st = curr;
        temp1 = temp1 -> next;
    }
    if(temp2 != NULL || carry != 0){
        st->next->data = (temp2->data + carry)%10;
        carry = (temp2->data + carry)/10;
        struct listNode * curr = (struct listNode *)malloc(sizeof(struct listNode));
        curr->data = 0;
        st->next = curr;
        st = curr;
        temp2 = temp2 -> next;
    }


}
void display(struct listNode * start){

    struct listNode * temp = start;
    while(temp != NULL){
        printf("%d",temp -> data);
        temp = temp -> next;
    }

}
int main(){

    struct listNode * head = (struct listNode *)malloc(sizeof(struct listNode));
    struct listNode * head1 = (struct listNode *)malloc(sizeof(struct listNode));
    struct listNode * head2 = (struct listNode *)malloc(sizeof(struct listNode));

    printf("-----MENU-----\n1.Print the number in decimal\n2.Print the number in hexadecimal\n3.Add the two numbers\n4.Substract two numbers\n5.Exit\n6.Make a list\n");
    while(1){
        int choice;
        scanf("%d",&choice);
        switch (choice){
            case 1:{
                display(head);
                break;
            }
            case 2:{
                display(head);
                break;
            }
            case 3:{
                addList(head1,head2);
                break;   
            }
            case 4:{
                subtractList(head1,head2);
                break;
            }
            case 5:{
                exit(1);
            }
            case 6:{
                addListNode(head1,head2);
                break;
            }
            default:{
                printf("Invalid input\n");
                break;
            }
        }
    }
}