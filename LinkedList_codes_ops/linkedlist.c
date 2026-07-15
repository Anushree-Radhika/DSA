#include<stdio.h>
#include<stdlib.h>
typedef struct listNode {
    struct listNode *next;
    int coef,expo;
}ll;

ll * addNode(ll* p1,int c,int e){
    ll * tem = p1;int note = 0;
    if(p1 == NULL){
        ll *tem = (ll *)malloc(sizeof(ll));
        tem->coef = c;
        tem->expo = e;
        tem -> next = NULL;
        p1 = tem;
        return p1;
    }
    else{
        while(!tem){
            if(tem -> expo == e){
                tem -> coef = c + tem ->coef;
                note = 1;
                break;
            }
            tem = tem -> next;
        }
        if(note == 0){
            ll *tem = (ll *)malloc(sizeof(ll));
            tem ->coef = c;
            tem ->expo = e;
            tem -> next = p1;
            p1 = tem;
            return p1;
        }
    }
}
ll * representation(ll * h1){
    ll *p = h1;
    while(p){
        printf("+ (%dx^%d)",p->coef,p->expo);
        p= p->next;
    }
    return h1;
}
ll *addpoly(ll*h1,ll*h2){
   ll * s1 = h1 ;
   ll * s2 = h2 ;
   ll * s3 = NULL;

   while(s1 != NULL && s2 != NULL){
    if(s3 == NULL){
        ll *tem = (ll *)malloc(sizeof(ll));
        if(s1 -> expo == s2 -> expo){
            tem -> expo = s1 -> expo;
            tem -> coef = s1 -> coef + s2 -> coef;
            s3 = tem;
        }
        else{
            ll *tem2 = (ll *)malloc(sizeof(ll));
            tem -> expo = s1 -> expo;
            tem -> coef = s1 ->coef;
            tem2 ->coef = s2 ->coef;
            tem2 ->expo = s2 -> expo;
            
            s3 = tem;
            tem -> next = tem2;
            tem2 -> next = NULL;
        }
        return s3;
    }
    else{
        ll *tem = (ll *)malloc(sizeof(ll));
        if(s1 -> expo == s2 -> expo){
            tem -> expo = s1 -> expo;
            tem -> coef = s1 -> coef + s2 -> coef;
            s3 = tem;
        }
        else{
            ll *tem2 = (ll *)malloc(sizeof(ll));
            tem -> expo = s1 -> expo;
            tem -> coef = s1 ->coef;
            tem2 ->coef = s2 ->coef;
            tem2 ->expo = s2 -> expo;
            
            s3 = tem;
            tem -> next = tem2;
            tem2 -> next = NULL;
        }
        return s3;


    }
    s1 = s1 -> next;
    s2 = s2 -> next;
   }
   return s3;
}

ll *subtractpoly(ll * h1 ,ll*h2){
    ll * s1 = h1;
    ll * s2 = h2;
    ll * s3 = NULL;
    while(s1 != NULL && s2 != NULL){

        if(s1 -> expo == s2->expo){
            ll *tem = (ll *)malloc(sizeof(ll));
            tem -> coef = s1 -> coef - s2 -> coef;
            tem -> expo = s1 -> expo;
            tem -> next = NULL;
            if(!s3){
                s3 = tem;
            }
            else{
                ll *w = s3 ;
                while(w->next){
                    w = w-> next;
                }
                w ->next = tem;
            }
        }
        else{
            ll *tem1 = (ll *)malloc(sizeof(ll));
            tem1 -> expo = s1 -> expo;
            tem1 -> coef = s1 -> coef;
            ll *tem2 = (ll *)malloc(sizeof(ll));
            tem2 -> expo = s2 -> expo;
            tem2 -> coef = -(s2 -> coef);
            tem1 -> next = tem2;
            if(!s3){
                s3 = tem1;
            }
            else{
                ll *w = s3 ;
                while(w->next){
                    w = w-> next;
                }
                w ->next = tem1;
            }
        }   
    }
    return s3;
}

int main(){
    ll *h1 = NULL;
    ll *h2 = NULL;ll *h3 = NULL;
    printf("MENU\n");
    printf("1.Enter the coefficient and exponent of the linkedlist\n");
    printf("2.ADD the two polynomial\n");
    printf("3.Subtract the two polynomial\n");
    printf("4.Exit\n");
    printf("5.Representation\n");


    while(1){

        printf("Enter choice:\n");
        int choice;
        scanf("%d",&choice);
        getchar();
        switch(choice){

            case 1:{
                int co1,ex1;
                printf("Input the coefficient and exponent of the first linkedlist\n");
                scanf("%d %d",&co1,&ex1);
                h1 = addNode(h1,co1,ex1);
                representation(h1);
                break;
            }
            case 2:{
                int n;
                scanf("%d",&n);getchar();
                while(n--){
                    int co2,ex2;
                    printf("Input the coefficient and exponent of the second linkedlist\n");
                    scanf("%d %d",&co2,&ex2);
                    h2 = addNode(h2,co2,ex2);
                }
                    representation(h2);
                    h3 = addpoly(h1,h2);
                    representation(h3);
                break;
            }
            case 3:{
                int n;
                scanf("%d",&n);getchar();
                while(n--){
                    int co2,ex2;
                    printf("Input the coefficient and exponent of the second linkedlist\n");
                    scanf("%d %d",&co2,&ex2);
                    h2 = addNode(h2,co2,ex2);
                }
                    representation(h2);
                    h3 = subtractpoly(h1,h2);
                    representation(h3);
                break;
            }
            case 4:{
                exit(0);
            }
            case  5:{
                representation(h1);
                representation(h2);
                representation(h3);
            }
        }
    }
    return 0;
}
