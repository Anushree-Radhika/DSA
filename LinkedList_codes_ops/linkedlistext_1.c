#include<stdio.h>
#include<stdlib.h>

typedef struct listNode {
    long long num;
    struct listNode *next;
}llNode;

typedef struct listNodechar {
    char alpha;
    struct listNodechar *next;
}hexaNode;

llNode * reverseHead(struct listNode *head){
    if(head == NULL || head -> next == NULL){
        return head ;
    }
    llNode * revHead = reverseHead(head -> next);
    llNode * front = head -> next;
    front -> next = head;
    head -> next = NULL;
    return revHead;
}
llNode *revrepresentation(long long n){
    if (n == 0) {
        llNode *node = malloc(sizeof(llNode));
        node->num = 0;
        node->next = NULL;
        return node;
    }
    llNode *start = NULL, *cur = NULL;
    while(n != 0){
        int rem = n % 10;
        if (start == NULL) {
            start = (llNode *)malloc(sizeof(llNode));
            start->num = rem;
            start->next = NULL;
            cur = start;
        } else {
            llNode *node = (llNode *)malloc(sizeof(llNode));
            node->num = rem;
            node->next = NULL;
            cur->next = node;
            cur = node;
        }
        n = n/10;
    }
    return start;
}

llNode *representation(long long n){
    if (n == 0) {
        llNode *node = malloc(sizeof(llNode));
        node->num = 0;
        node->next = NULL;
        return node;
    }
    llNode *start = NULL, *cur = NULL;
    while(n != 0){
        int rem = n % 10;
        if (start == NULL) {
            start = (llNode *)malloc(sizeof(llNode));
            start->num = rem;
            start->next = NULL;
            cur = start;
        } else {
            llNode *node = (llNode *)malloc(sizeof(llNode));
            node->num = rem;
            node->next = NULL;
            cur->next = node;
            cur = node;
        }
        n = n/10;
    }
    start = reverseHead(start);
    return start;
}
llNode *addition(long long n1,long long n2){

    llNode *ll1 = revrepresentation(n1);
    llNode *ll2 = revrepresentation(n2);
    llNode *h1 = ll1;
    llNode *h2 = ll2;

    if(h1 == NULL){
        h2 = reverseHead(h2);
        return h2;
    }
    if(h2 == NULL){
        h1 = reverseHead(h1);
        return h1;
    }
    int carry =0;
    llNode *sum = NULL;
    llNode *cur = NULL;
    while(h1 != NULL && h2 != NULL){
        if(sum == NULL){
            sum = (llNode *)malloc(sizeof(llNode));
            sum -> num = (h1 -> num + h2 -> num + carry)%10;
            carry = (h1 -> num + h2 -> num + carry)/10;
            cur = sum;
        }
        else{
             llNode *node = (llNode *)malloc(sizeof(llNode));
            node -> num = (h1 -> num + h2 -> num + carry)%10;
            carry = (h1 -> num + h2 -> num + carry)/10;
            cur -> next = node;
            node -> next = NULL;
        }
        h1 = h1 -> next;
        h2 = h2 -> next;
    }
    while(h1 != NULL){
        llNode *node = (llNode *)malloc(sizeof(llNode));
        node -> num = (h1 -> num + carry)%10;
        carry = (h1 -> num  + carry)/10;
        cur -> next = node;
        node -> next = NULL;
        cur = node;
        h1 = h1 -> next;
    }
    while(h2 != NULL){
        llNode *node = (llNode *)malloc(sizeof(llNode));
        node -> num = (h2 -> num + carry)%10;
        carry = (h2 -> num  + carry)/10;
        cur -> next = node;
        node -> next = NULL;
        cur = node;
        h2 = h2 -> next;
    }
    if (carry != 0) {
        llNode *node = (llNode *)malloc(sizeof(llNode));
        node->num = carry;
        node->next = NULL;
        cur->next = node;
    }
    sum = reverseHead(sum);
    return sum;
}
// llNode *substraction(long long n1,long long n2){
//     llNode *ll1 = revrepresentation(n1);
//     llNode *ll2 = revrepresentation(n2);
//     llNode *h1 = ll1;
//     llNode *h2 = ll2;

//     if(h1 == NULL){
//         h2 = reverseHead(h2);
//         return h2;
//     }
//     if(h2 == NULL){
//         h1 = reverseHead(h1);
//         return h1;
//     }
//     int borrow =0;
//     llNode *diff = NULL;
//     llNode *cur = diff;
//     while(h1 != NULL && h2 != NULL){
//         if(diff == NULL){
//             diff = (llNode *)malloc(sizeof(llNode));
//             if(h1 -> num >= h2 -> num){
//                 diff -> num = (h1 -> num - h2 -> num);
//                 borrow = 0;
//             }
//             else{
//                 borrow = 1;
//                 diff -> num = 10+(h1 ->num) - (h2 -> num);
                
//             } 
//             cur = diff;
//         }
//         else{
//             llNode *node = (llNode *)malloc(sizeof(llNode));
//             if(h1 -> num >= h2 -> num){
//                 node -> num = (h1 -> num - h2 -> num);
//                 borrow = 0;
//             }
//             else{
//                 borrow = 1;
//                 node -> num = 10+(h1 ->num) - (h2 -> num);
//                 h1 -> next -> num --;
//             }
//             cur -> next = node;
//             cur = node;
//         }
//         h1 = h1 -> next;
//         h2 = h2 -> next;
//     }
//     while(h1 != NULL){
//         llNode *cur = diff;
//         llNode *node = (llNode *)malloc(sizeof(llNode));
//         while(cur -> next != NULL){
//             cur = cur -> next;
//         }
//         node -> num = h1 -> num ;
//         cur -> next = node;
//         node -> next = NULL;
//         h1 = h1 -> next;
//     }
//     while(h2 != NULL){
//         llNode *cur = diff;
//         llNode *node = (llNode *)malloc(sizeof(llNode));
//         while(cur -> next != NULL){
//             cur = cur -> next;
//         }
//         node -> num = h2 -> num ;
//         cur -> next = node;
//         node -> next = NULL;
//         h2 = h2 -> next;
//     }
//     return diff;


llNode *substraction(long long n1, long long n2){
    // Handle negative results
    int negative = 0;
    if(n1 < n2){
        long long tmp = n1;
        n1 = n2;
        n2 = tmp;
        negative = 1;
    }

    llNode *ll1 = revrepresentation(n1);
    llNode *ll2 = revrepresentation(n2);
    llNode *h1 = ll1;
    llNode *h2 = ll2;

    llNode *diff = NULL;
    llNode *cur = NULL;
    int borrow = 0;

    while(h1 != NULL){
        int x = h1->num - borrow;
        int y = (h2 ? h2->num : 0);

        if(x < y){
            x += 10;
            borrow = 1;
        } else borrow = 0;

        int d = x - y;

        llNode *node = malloc(sizeof(llNode));
        node->num = d;
        node->next = NULL;

        if(!diff){
            diff = cur = node;
        } else {
            cur->next = node;
            cur = node;
        }

        h1 = h1->next;
        if(h2) h2 = h2->next;
    }

    // Remove trailing zeros (from LSB side)
    llNode *lastNonZero = NULL, *temp = diff;
    while(temp){
        if(temp->num != 0) lastNonZero = temp;
        temp = temp->next;
    }
    if(lastNonZero == NULL){ // result is zero
        llNode *zeroNode = malloc(sizeof(llNode));
        zeroNode->num = 0;
        zeroNode->next = NULL;
        return zeroNode;
    }
    // cut off extra zeros
    temp = lastNonZero->next;
    lastNonZero->next = NULL;
    while(temp){
        llNode *t = temp;
        temp = temp->next;
        free(t);
    }

    diff = reverseHead(diff); // reverse to MSB-first

    if(negative) printf("-"); // print negative sign

    return diff;
}

void print(llNode *a){
    llNode *n= a;
    while(n != NULL){
        printf("%lld",n ->num);
        n = n -> next;
    }
    printf("\n");
    return ;
}

int main(){

    long long num1,num2;

    printf("Input the first number:");
    scanf("%lld",&num1);
    getchar();
    printf("Input the second number:");
    scanf("%lld",&num2);
    getchar();
    printf("MENU\n");
    printf("1. Representation of numbers\n");
    printf("2. Reverse representation of numbers\n");
    printf("3. Addition of numbers\n");
    printf("4. Substraction of numbers\n");
    printf("5. Exit\n");
    while(1){

        printf("Input choice:");
        int choice;
        scanf("%d",&choice);
        getchar();

        switch(choice){

            case 1:{
                llNode *rep1 = representation(num1);
                print(rep1);
                llNode *rep2 = representation(num2);
                print(rep2);
                break;
            }
            case 2:{
                llNode *rep1 = revrepresentation(num1);
                print(rep1);
                llNode *rep2 = revrepresentation(num2);
                print(rep2);
                break;
            }
            case 3:{
                llNode *ans = addition(num1,num2);
                print(ans);
                break;
            }
            case 4:{
                llNode * ans = substraction(num1,num2);
                print(ans);
                break;
            }
            case 5:{
                exit(0);
            }
        }
    }
    return 0;
}