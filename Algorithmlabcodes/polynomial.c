#include<stdio.h>
#include<stdlib.h>
typedef struct poly_node {
    int coef; // stores coefficient 
    int expon; // stores exponenet
    struct poly_node * next;
}polynode;

polynode* createnode(int co, int exp){
    polynode* newNode = (polynode *)malloc(sizeof(polynode)); 
    newNode -> coef = co;
    newNode -> expon = exp;
    newNode -> next = NULL;
    return newNode ;
}
polynode* insertTerm(polynode *head, int coeff, int exp){
    polynode* newNode = createnode(coeff,exp);
    polynode* nd = head;
    if (head == NULL) return newNode;
    if (exp == head->expon) {
        head->coef += coeff;
        free(newNode);
        return head;
    }
    if (exp > head->expon) {
        newNode->next = head;
        return newNode;
    }
    while(nd->next != NULL && exp < nd ->next -> expon){
        nd = nd -> next ;
    }
    if (nd->next != NULL && nd->next->expon == exp) {
        nd->next->coef += coeff; // combine like terms
        free(newNode);
    } else {
        newNode->next = nd->next;
        nd->next = newNode;
    }
    return head;
}
void display(polynode *head){
    polynode *pol = head ;
    while(pol != NULL){
        printf("+(%d)x^%d",pol->coef,pol ->expon);
        pol = pol -> next;
    }
    printf("\n");
}

polynode* addpoly(polynode *head1,polynode *head2){
    polynode *h1 = head1,*h2 = head2;
    polynode *h3 = createnode(0,0);
    polynode *curr = h3;
    while(h1 != NULL && h2 != NULL){
        
        if(h1 ->expon > h2 ->expon){
            polynode *newNode = createnode(h1->coef ,h1 ->expon);
            curr ->next = newNode;
            newNode -> next = NULL;
            curr = newNode;
            h1 = h1 -> next;
        }
        if( h2 ->expon > h1 ->expon){
            polynode *newNode = createnode(h2->coef ,h2->expon);
            curr ->next = newNode;
            newNode -> next = NULL;curr = newNode;
            h2 = h2 -> next;
        }
        if( h1 ->expon == h2 -> expon){
            polynode *newNode = createnode(h1->coef + h2 ->coef ,h1 ->expon);
            curr ->next = newNode;
            newNode -> next = NULL;
            curr = newNode;
            h1 = h1 -> next;h2 = h2 -> next;
        }
    }
    while(h1 != NULL){
        polynode *newNode = createnode(h1->coef ,h1 ->expon);
        curr ->next = newNode;
        newNode -> next = NULL;curr = newNode;
        h1 = h1 -> next;
    }
    while(h2 != NULL){
        polynode *newNode = createnode(h2->coef ,h2->expon);
        curr ->next = newNode;
        newNode -> next = NULL;curr = newNode;
        h2 = h2 -> next;
    }
    return h3->next;
}

polynode* subpoly(polynode *head1,polynode *head2){
    polynode *h1 = head1,*h2 = head2;
    polynode *h3 = createnode(0,0);
    polynode *curr = h3;
    while(h1 != NULL && h2 != NULL){
        
        if(h1 ->expon > h2 ->expon){
            polynode *newNode = createnode(h1->coef ,h1 ->expon);
            curr ->next = newNode;
            newNode -> next = NULL;
            curr = newNode;
            h1 = h1 -> next;
        }
        if( h2 ->expon > h1 ->expon){
            polynode *newNode = createnode(h2->coef ,h2->expon);
            curr ->next = newNode;
            newNode -> next = NULL;curr = newNode;
            h2 = h2 -> next;
        }
        if( h1 ->expon == h2 -> expon){
            polynode *newNode = createnode(h1->coef - h2 ->coef ,h1 ->expon);
            curr ->next = newNode;
            newNode -> next = NULL;
            curr = newNode;
            h1 = h1 -> next;h2 = h2 -> next;
        }
    }
    while(h1 != NULL){
        polynode *newNode = createnode(h1->coef ,h1 ->expon);
        curr ->next = newNode;
        newNode -> next = NULL;curr = newNode;
        h1 = h1 -> next;
    }
    while(h2 != NULL){
        polynode *newNode = createnode(-h2->coef ,h2->expon);
        curr ->next = newNode;
        newNode -> next = NULL;curr = newNode;
        h2 = h2 -> next;
    }
    return h3->next;
}

int main(){

    polynode *linkl1 = NULL,*linkl2 = NULL,*linkl3 = NULL,*ans = NULL; 
    printf("MENU\n");
    printf("1.Insert a polynomial term\n");
    printf("2.Add polynomial\n");
    printf("3.Substract polynomial\n");
    printf("4.Display polynomial\n");
    printf("5.Exit\n");

    while(1){

        int choice;
        printf("Enter choice :");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:{

                printf("Enter coefficient and exponent of the polynomial.\n");
                int coeff,expo;
                scanf("%d %d",&coeff,&expo);getchar();
                linkl1 = insertTerm(linkl1,coeff,expo);
                display(linkl1);
                break;
            }
            case 2:{
                printf("Enter length of the second linkedlist you want to add:\n");
                int llength;
                scanf("%d",&llength);
                getchar();
                while(llength --){
                    int coe,ex;
                    scanf("%d %d",&coe,&ex);getchar();
                    linkl2 = insertTerm(linkl2,coe,ex);
                }
                display(linkl2);
                ans = addpoly(linkl1,linkl2);
                display(ans);
                break;
            }
            case 3:{
                printf("Enter length of the second linkedlist you want to substract:\n");
                int llength;
                scanf("%d",&llength);
                getchar();
                while(llength --){
                    int coe,ex;
                    scanf("%d %d",&coe,&ex);getchar();
                    linkl3 = insertTerm(linkl3,coe,ex);
                }
                display(linkl3);
                ans = subpoly(linkl1,linkl3);
                display(ans);
                break;
            }
            case 4:{
                display(linkl1);break;
            }
            case 5:{
                exit(1);
            }
        }
    }
    return 0;
}