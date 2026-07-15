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
int isPresentListNodeSorted(struct listNode *start, int elem){
    struct listNode *dum = start;
    int count = 0;
    while(dum != NULL){
        if(dum->data == elem){
            return count;  // ony return position
        }
        count++;
        dum = dum->next;
    }
    return -1; // not found
}
struct listNode *deleteListNodeSorted(struct listNode *start, int elem) {

    if (start == NULL) {
        printf("List is empty!\n");
        return start;
    }
    if ( isPresentListNodeSorted(start, elem) == -1) {
        printf("The %d is not present in the linked list\n", elem);
    }
    struct listNode *curr = start;
    struct listNode *prev = NULL;

    // Case 1: delete from head (multiple duplicates at head too)
    while (curr != NULL && curr->data == elem) {
        struct listNode *temp = curr;
        curr = curr->next;
        free(temp);
        start = curr;   // update head
    }
    // Case 2: delete from middle or end
    while (curr != NULL) {
        if (curr->data == elem) {
            struct listNode *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            free(temp);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return start;
}

void printList(struct listNode *start){

    struct listNode *dummy;
    dummy = start;
    while(dummy != NULL){
        printf("%d->",dummy->data);
        dummy = dummy ->next;
    }
    printf("NULL\n");
}


struct listNode* freeListNodeSorted(struct listNode *start){

    struct listNode *curr = start;
    struct listNode *prev = curr;

    while(curr != NULL){
        prev = curr;
        curr = curr ->next;
        free(prev);
    }

    return NULL;
}
struct listNode * reverseListNodeSorted(struct listNode *start){
    struct listNode *curr = start,*prev = NULL , *up;
    while(curr != NULL){
        up = curr->next;
        curr-> next = prev;
        prev = curr;
        curr = up;
    }
    return prev;

    // if(start == NULL || start->next == NULL){
    //     return start;
    // }
    // struct listNode *newHead = reverseListNodeSorted(start->next);
    // struct listNode *front = start ->next;
    // front -> next = start;
    // start -> next = NULL;
    // return newHead;
}

void updateListNode(struct listNode *start){

    struct listNode *curr = start;
    srand(time(NULL));
    while(curr != NULL){

        curr -> data = curr -> data + rand();
        curr = curr->next;
    }
}
struct listNode *sortListNode(struct listNode *start){

    struct listNode *curr = start;
    // struct listNode *temp2 = curr ->next;
    while(curr != NULL && curr -> next != NULL){
        struct listNode *temp2 = curr ->next;
        while(temp2 != NULL){
            if(curr->data < temp2->data){
                int t = curr ->data;
                curr ->data = temp2 ->data;
                temp2 ->data = t;
            }
            temp2 = temp2 ->next;
        }
        curr = curr -> next;
    }
    return start;
}

struct listNode* mergeListNodeSorted(struct listNode *start1 , struct listNode *start2){

    struct listNode *temp = start1;
    if (start1 == NULL) return start2;
    if (start2 == NULL) return start1;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp -> next = start2;
    start1 = sortListNode(start1);
    return start1;

}
int main(){
    
    printf("MENU\n");
    printf("1. Insert element\n");
    printf("2. Delete element\n");
    printf("3. SEARCH Element in the LL\n");
    printf("4. Print Elementsin the LL\n");
    printf("5. Free all nodes\n");
    printf("6. Reverse all nodes\n");
    printf("7. Update all nodes\n");
    printf("8. Sort all the nodes in descending order again\n");
    printf("9. Merge two lists in a sorted order\n");
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
                if(c == -1){
                    printf("Not found\n");
                }
                else{
                    printf("Present in the list\n");
                }
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
                head = freeListNodeSorted(head);
                break;
            }
            case 6:{
                head = reverseListNodeSorted(head);
                break;
            }
            case 7:{
                updateListNode(head);
                break;
            }
            case 8:{
                head = sortListNode(head);
                break;
            }
            case 9:{
                struct listNode *head1 = NULL;
                printf("Enter first list elements:");
                int si1;
                printf("Enter the number of elements in the list:");
                scanf("%d", &si1);
                for(int i =0;i<si1;i++){
                    int el;
                    scanf("%d",&el);
                    head1 = addListNodeSorted(head1,el);
                }
                
                struct listNode *head2 = NULL;
                printf("Enter second list elements:");
                int si2;
                printf("Enter the number of elements in the list:");
                scanf("%d", &si2);
                for(int i =0;i<si2;i++){
                    int el;
                    scanf("%d",&el);
                    head2 = addListNodeSorted(head2,el);
                }
                head = mergeListNodeSorted(head1,head2);
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
