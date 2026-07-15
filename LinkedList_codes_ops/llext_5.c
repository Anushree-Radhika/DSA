#include<stdio.h>
#include<stdlib.h>
typedef struct listNode {
    int data;
    struct listNode *prev;
    struct listNode * next;
}ln;
ln *createLL(ln *link1,int val){

    ln *curr = link1;
    if(link1 == NULL){
        ln *l1= (ln*)malloc(sizeof(ln));
        l1 -> data = val;
        l1 -> next = NULL;
        l1 -> prev = NULL;
        link1 = l1;
        return link1;
    }

    while(curr -> next != NULL){
        curr = curr -> next;
    }
    ln *l1= (ln*)malloc(sizeof(ln));
    l1 -> data = val;
    l1 -> next = NULL;
    curr -> next = l1;
    l1 -> prev = curr;
    curr = curr -> next;
    curr -> next = NULL;
    return link1;
}
ln *createCircularLL(ln *head){
    ln *curr = head;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    curr -> next = head;
    return head;
}

int createMemoryPoolNodes(ln *head,int m){
    ln *curr = head;
    ln *t = NULL;
    while(m--){
        if(curr == NULL){
            curr = (ln *)malloc(sizeof(ln));
            curr -> next = NULL;
        }
        else{
            t = (ln *)malloc(sizeof(ln));
            curr -> next = t;
            t->next = NULL;
            curr = curr -> next;
        }
    }
    return head;
}

int releaseMemoryPoolNodes(ln *head,int m){
    ln *curr = head;int n;
    while(curr != NULL){
        ln * temp = curr ->next ;
        free(curr);
        curr = temp;
        n++;
    }
    return m - n;
}

ln **getNode(ln *head){
    ln **address = &(head);
    return address;
}
void releaseNode(ln **t){
    


}




int gameimplementation(ln *head){

    ln *curr = head;
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
    printf("Give the user input of number of nodes:");
    scanf("%d",&n);
    ln *circularll =  (ln *)malloc(sizeof(ln)*n);
      
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
                int m;
                while(n--){
                    printf("Input element to insert\n");
                    scanf("%d",&m);
                    getchar();
                    circularll = createMemoryPoolNodes(circularll,m);
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
