#include<stdio.h>
#include<stdlib.h>

typedef struct listNode {
    int data;
    struct listNode *next;
    struct listNode *prev;
}LN;
LN *createLL(struct listNode *link1,int val){

    LN *curr = link1;
    if(link1 == NULL){
        LN *l1= (LN*)malloc(sizeof(LN));
        l1 -> data = val;
        l1 -> next = NULL;
        l1 -> prev = NULL;
        link1 = l1;
        return link1;
    }

    while(curr -> next != NULL){
        curr = curr -> next;
    }
    LN *l1= (LN*)malloc(sizeof(LN));
    l1 -> data = val;
    l1 -> next = NULL;
    curr -> next = l1;
    l1 -> prev = curr;
    curr = curr -> next;
    curr -> next = NULL;
    return link1;
}

LN *createCircularLL(LN *head){
    LN *curr = head;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    curr -> next = head;
    head -> prev = curr;
    return head;
}

int gameimplementation(LN *head){
    LN *curr = head;
    while(curr != curr -> next){
        int s = 0;
        s = (rand() % 31) -15;
        printf("The number that gets skipped:%d\n",s);
        if(s > 0){
            int c = abs(s)-1;
            while(c--){
                curr = curr-> next;
            }
            struct listNode *temp = curr -> next;
            printf("%d ",temp -> data);
            curr -> next = curr -> next -> next;
            curr -> next-> prev = curr;
            free(temp);
            curr = curr -> next;
        }
        else if(s== 0){
            s = 1;
        }
        else{
            int c = abs(s)-1;
            while(c--){
                curr = curr-> prev;
            }
            struct listNode *temp = curr -> prev;
            printf("%d ",temp -> data);
            curr -> prev = curr -> prev -> prev;
            free(temp);
            curr->prev->next = curr;
            curr = curr -> prev;
        }
    }
    return curr -> data;
}

int main(){

    int n;
    printf("Give the user input of number of players:");
    scanf("%d",&n);
    LN *circularll =  NULL;
      
    printf("MENU\n");
    printf("1. Insert the linkedlist\n");
    printf("2. Create a circular linkedlist\n");
    printf("3. Run the game and pop the elements sequentially and declare winner\n");
    printf("4. Exit\n");

    while(1){

        printf("Enter choice :");
        int choice;
        scanf("%d",&choice);
        switch(choice) {
            case 1:{
                int e;
                while(n--){
                    printf("Input element to insert\n");
                    scanf("%d",&e);
                    getchar();
                    circularll = createLL(circularll, e);
                }
                break;
            }
            case 2:{
                circularll = createCircularLL(circularll);
                break;
            }
            case 3:{
                int c = gameimplementation(circularll);
                printf("The winner of the game is:");
                printf("%d\n",c);
                break;
            }
            case 4:{
                exit(1);
            }
            default:{
                printf("Input valid integer\n");
            }
        }
    }
    return 0;
}