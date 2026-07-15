#include<stdio.h>
#include<stdlib.h>
typedef struct listNode{
    int data;
    struct listNode *next;
}ll;
ll *addNode(ll *start, int elem){

    ll *temp = (ll *)malloc(sizeof(ll));
    temp->data = elem;
    temp->next = NULL;

    if(start == NULL){
        start = temp;
        return start;
    }
    else{
        ll * t = start;
        while(t-> next != NULL){
                t = t-> next;
        }
        t -> next = temp;
        return start;
    }
}

int check(ll *list){
    ll *li = list;
    while(li != NULL && li-> next != NULL){
        if(li -> data > li-> next ->data){
            return 0;
        }
        else{
            li = li -> next;
        }
    }
    return 1;
}
ll *sort(ll *start){

    if(start == NULL||start -> next == NULL){
            return start;
    }
    ll *newnode = (ll *)malloc(sizeof(ll));
    newnode -> data = 0;
    newnode -> next = start;
    ll *temp = start->next;
    ll *cur = start;
    ll * prev = newnode;
    while (!check(start)){
        prev = newnode;
        temp = start -> next;
        cur = start;
    
        while(temp != NULL){
            if(temp ->data < cur -> data && cur != prev){
                ll * re = temp-> next ;
                temp -> next = cur;
                cur -> next = re;
                prev -> next = temp;
            }
            else{
                cur = temp;
            }
            temp = temp -> next;
            prev= prev -> next;
        }
        start = newnode -> next;
    }
    return start;
}
ll *merge(ll *start1,ll * start2){

    ll * h1 = start1;
    ll * h2 = start2;
    ll * h3 = NULL;   
    h1 = sort(h1);
    h2 = sort(h2);
    while(h1 != NULL && h2 != NULL){
        if(h1 -> data > h2 -> data){
            h3 = addNode(h3,h2 -> data);
            h2 = h2 -> next;
        }
        else{
            h3 = addNode(h3,h1 -> data);
            h1 = h1 -> next;
        }
    }
    while(h1 != NULL){
        h3 = addNode(h3,h1 -> data);
        h1 = h1 -> next;
    }
    while(h2 != NULL){
        h3 = addNode(h3,h2 -> data);
        h2 = h2 -> next;
    }
    return h3;
}

void print(ll *list){
    ll *dummy;
    dummy = list;
    while(dummy != NULL){
        printf("%d->",dummy->data);
        dummy = dummy ->next;
    }
    printf("NULL\n");
}
int main(){
        ll *list = NULL,*list1 = NULL;
        printf("MENU\n");
        printf("Form a singly linkedlist\n");
        printf("1.Sort\n");
        printf("2.Merge\n");
        printf("3.Print\n");
        printf("4.Exit\n");
        while(1){

            int choice;
            scanf("%d",&choice);

            switch(choice){
                case 0:{
                    int k;
                    scanf("%d",&k);getchar();
                    list = addNode(list,k);
                    break;
                }
                case 1:{
                    list = sort(list);
                    break;
                }
                case 2:{
                    ll *list2 = NULL;
                    int q;
                    printf("Input the number of nodes :\n");
                    scanf("%d",&q);getchar();
                    while(q--){
                        printf("Enter val to insert in the linkedlist:");
                        int c;
                        scanf("%d",&c);getchar();
                        list2 = addNode(list2,c);
                    }
                    list1 = merge(list,list2);
                    print(list1);
                    break;
                }
                case 3:{
                    print(list);
                    break;

                }
                case 4:{
                    exit(0);
                }
                default:{
                    printf("Invalid input\n");
                }
            }
        }
    return 0;
}                    
