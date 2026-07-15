#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining linkedlist
typedef struct largeNumNode {
    char digit;
    struct largeNumNode * next;
}llnode;

//reversing a linkedlist
struct largeNumNode * reverseHead(struct largeNumNode *head){

    if(head == NULL || head -> next == NULL){
        return head ;
    }
    struct largeNumNode * revHead = reverseHead(head -> next);
    struct largeNumNode * front = head -> next;
    front -> next = head;
    head -> next = NULL;
    return revHead;

    // struct largeNumNode * curr = head , *up = curr -> next,*temp ;
    // while(temp != NULL){
    //     curr -> next = NULL;
    //     temp = up -> next;
    //     up -> next = curr;
    //     curr = up;
    //     up = temp;
    // }
    // return curr;

}

// decimal number in alinkedlist
struct largeNumNode* larged(long long num){

    int rem ;
    // first allocate memory to store the num
    struct largeNumNode *head = (struct largeNumNode *)malloc(sizeof(struct largeNumNode));

    head -> next = NULL;
    head -> digit = '-';
    struct largeNumNode *curr = head ;

    while (num != 0){

        rem = num % 10;
        if(head-> digit == -1 ){
            head -> digit = rem + '0' ;
            // itoa(rem)ndonot use as it converts to string
            head -> next = NULL;
            curr = head ; 
        }
        struct largeNumNode *tem = (struct largeNumNode *)malloc(sizeof(struct largeNumNode));
        // itoa(rem)ndonot use as it converts to string
        tem -> digit = rem +'0';
        tem -> next  = NULL;
        curr->next = tem;
        num = num/10;
        curr = tem;
    }
    head = reverseHead(head);
    return head;
}

//hexadecimal
struct largeNumNode* largeh(long long num){

    int rem ;
    // first allocate memory to store the num
    struct largeNumNode *head = (struct largeNumNode *)malloc(sizeof(struct largeNumNode));
    head -> next = NULL;
    head -> digit = '-';
    struct largeNumNode *curr = head ;

    while (num != 0){

        rem = num % 16;
        if(head-> digit == -1){

            if(rem >=0 && rem <= 9){
                head -> digit = rem + '0' ;
                // itoa(rem)ndonot use as it converts to string
                head -> next = NULL;
                curr = head ; 
            }
            else if(rem >=10 && rem <= 15){
                head -> digit = (rem - 10) + 'A';
                head -> next = NULL;
                curr = head ; 
            } 

        }
        struct largeNumNode *tem = (struct largeNumNode *)malloc(sizeof(struct largeNumNode));
        // itoa(rem)ndonot use as it converts to string
        if(rem >=0 && rem <= 9){
            tem -> digit = rem + '0' ;
        }
        else{
            tem -> digit = (rem - 10) + 'A';
        }
        tem -> next  = NULL;
        curr->next = tem;
        num = num/16;
        curr = tem;
    }
    head = reverseHead(head);
    return head;
}
struct largeNumNode* add(int num1,int num2){
    llnode *start1 = larged(num1);
    llnode *start2 = larged(num2);
    llnode *h1 = start1;
    llnode *h2 = start2;

    h1 = reverseHead(h1);
    h2 = reverseHead(h2);

    llnode *sum = (llnode *)malloc(sizeof(llnode));
    sum = NULL;
    int carry = 0;llnode *curr = sum;
    while(h1 != NULL && h2 != NULL){

        if(sum == NULL){
            sum -> data = (h1 -> data + h2 -> data + carry)%10;
            carry = (h1 -> data + h2 -> data + carry)/10 ;
            sum -> next = NULL;
        }
        else{
            struct listNode *node = (struct listNode *)malloc(sizeof(struct listNode));
            node -> data = (h1 -> data + h2 -> data + carry)%10;
            carry = (h1 -> data + h2 -> data + carry)/10 ;
            curr -> next = node;
            curr = node;
            node -> next = NULL;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    while(h1 != NULL){

        struct listNode *node = (struct listNode *)malloc(sizeof(struct listNode));
        node -> data = (h1 -> data + carry)%10;
        carry = (h1 -> data + carry)/10 ;
        curr -> next = node;
        curr = node;
        node -> next = NULL;
        
        h1 = h1->next;
    }

    while(h2 != NULL){

        struct listNode *node = (struct listNode *)malloc(sizeof(struct listNode));
        node -> data = (h2 -> data + carry)%10;
        carry = (h2 -> data + carry)/10 ;
        curr -> next = node;
        curr = node;
        node -> next = NULL;
        
        h2 = h2->next;
    }

    sum = reverseHead(sum);
    return sum;
}
// printing a linkedlist
void print(struct largeNumNode *a){
    struct largeNumNode *num = a;
    while(num != NULL){
        if(num -> digit == '-'){
            num = num -> next;
            continue;
        }
        printf("%c ->",num -> digit);
        num = num -> next;
    }
    printf("NULL\n");
    return ;

}


int main(){
    
    long long num ;
    printf("Input number you want to represent linkedlist as:");
    scanf("%lld",&num);
    getchar();

    struct largeNumNode * ans = NULL;

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
                struct largeNumNode * ans = larged(num);print(ans);
            }
            case 2:{
                struct largeNumNode * ans = largeh(num);print(ans);
            }
            case 3:{

            }
            case 4:{

            }
            case 5:{
                exit(1);
            }
        }

    }
   
    return 0;
}