#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top,capacity;
    char *element;
};
void initialize(struct stack *s,int size){

    s->top = -1;
    s->capacity = size;
    s->element = (char *)malloc(sizeof(char) * size);

}
int isStackFull(struct stack *s){
    if(s->top + 1 == s->capacity){
        return 1;
    }
    else{
        return 0;
    }
}
int isStackEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int push(struct stack *s,int value){
    if(isStackFull(s)){
        return 0;
    }
    s->element[ ++s->top] = value;
    return 1;
}
int pop(struct stack *s){
    if(isStackEmpty(s)){
        return 0;
    }
    int x = s->element[s->top];
    s->top --;
    return x;
}

int palindrome(char *str,struct stack s){

    int len = strlen(str);
    // push first half
    for (int i = 0; i < len / 2; i++) {
        push(&s, str[i]);
    }

    // skip middle character if odd
    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;

    // check second half
    for (int i = start; i < len; i++) {
        if (str[i] != pop(&s)) {
            return 0;
        }
    }
    return 1;

}
int main(){
    struct stack s;
    int si;
    printf("Input size of string:\n");
    scanf("%d",&si);
    getchar();
    initialize(&s,si);
    printf("Enter the string:\n");
    char c[si+1];
    fgets(c,si+1,stdin);
    c[strcspn(c, "\n")] = 0;
    if(palindrome(c,s)){
        printf("The string is a palindrome.\n");
    }
    else{
        printf("The string is not a palindrome.\n"); 
    }
    return 0;
}
