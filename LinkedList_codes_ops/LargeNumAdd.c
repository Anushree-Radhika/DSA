#include<stdio.h>
#include<stdlib.h>
typedef struct listNode {
    int data;
    struct listNode *next;
}ll;

ll * createNode(long long num){
    ll * s =NULL;
    while(num != 0){
        int rem = num% 10;
        ll * tem =  (ll *)malloc(sizeof(ll));
        tem-> data = rem;
        tem -> next = NULL;
        if(s == NULL){
            s = tem;
        }
        else{
            ll * cur = s;
            while(cur -> next != NULL){
                cur = cur -> next;
            }
            cur -> next = tem;
        }
        num /= 10;
    }
    return s;
}

ll* reverseH(ll *n){
    if(n == NULL || n->next == NULL){
        return n;
    }
    ll *reversehead = reverseH(n -> next);
    ll *front = n-> next;
    ll *cur = n ;
    front -> next = cur;
    cur -> next = NULL;
    return reversehead;
}
ll *addTwoLargeNum(ll * n1,ll *n2){
    if(n1 == NULL && n2 == NULL){
        return NULL;
    }
    else if(n1 == NULL){
        return n2;
    }
    else if(n2 == NULL){
        return n1;
    }
    else{
        ll * addedNode = NULL;int carry =0 ;

        while(n1 != NULL && n2 != NULL){
            ll *nod = (ll *)malloc(sizeof(ll));
            int d = (n1 -> data + n2 -> data +carry)%10;
            carry = (n1 -> data + n2 -> data +carry)/10;
            nod -> data = d;
            nod->next = NULL;
            if(addedNode == NULL){
                addedNode = nod;
            }
            else{
                ll * cur = addedNode;
                while(cur -> next != NULL){
                    cur = cur -> next;
                }
                cur -> next = nod;
            }
            n1 = n1 -> next;
            n2 = n2 -> next;
        }
        while(n1 != NULL){
            ll *nod = (ll *)malloc(sizeof(ll));
            int d = (n1 -> data +carry)%10;
            carry = (n1 -> data +carry)/10;
            nod -> data = d;nod->next = NULL;
            ll * cur = addedNode;
            while(cur -> next != NULL){
                cur = cur -> next;
            }
            cur -> next = nod;
            n1 = n1 -> next;
        }
        while(n2 != NULL){
            ll *nod = (ll *)malloc(sizeof(ll));
            int d = (n2 -> data +carry)%10;
            carry = (n2 -> data +carry)/10;
            nod -> data = d;nod->next = NULL;
            ll * cur = addedNode;
            while(cur -> next != NULL){
                cur = cur -> next;
            }
            cur -> next = nod;
            n2 = n2 -> next;
        }
        if(carry > 0){
            ll *nod = (ll *)malloc(sizeof(ll));
            nod->data = carry;
            nod->next = NULL;
            ll *cur = addedNode;
            while(cur->next != NULL) cur = cur->next;
            cur->next = nod;
        }
        addedNode = reverseH(addedNode);
        return addedNode;
    }
}


ll *subtract(ll * n){


}
void print(ll * h){

    ll * r = h;
    while(r!= NULL){
        printf("%d->",r->data);
        r = r -> next;
    }

}
int main(){

    long long num ;
    printf("Input number you want to represent linkedlist as:");
    scanf("%lld",&num);
    getchar();
    ll * ans = NULL;

    printf("MENU\n");
    printf("1. Decimal representation of the number\n");
    printf("2. Hexadecimal representation of the number\n");
    printf("3. Add Elements in the LL\n");
    printf("4. Subtract Elements in the LL\n");
    printf("5. Exit\n");

    while(1){

        printf("Enter choice :");
        int choice;
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:{
                ans = createNode(num);
                ans = reverseH(ans);
                print(ans);break;
            }
            // case 2:{
            //     ll * ans = largeh(num);print(ans);
            // }
            case 3:{
                long long num2;
                printf("Input number you want to add to the linkedlist as:");
                scanf("%lld", &num2);
                getchar();

                ll *l2 = createNode(num2); // l2 also has least significant digit first
                ll *sum = addTwoLargeNum(reverseH(ans), l2); // add directly since both are aligned
                print(sum);
                break;
            }
            // case 4:{

            // }
            case 5:{
                exit(1);
            }
        }

    }
   
    return 0;
}
