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
int push(struct stack *s,char value){
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
int matching_pare(char open ,char close){
    return (open && close) == (('(' && ')') || ('{' && '}') || ('[' && ']'));
}

int paren(struct stack *s, char exp[]){

    for(int i =0;i<strlen(exp) ;i++){
        char ch = exp[i];
        if(ch == ')'){
            if(!isStackEmpty(s) && pop(s) != '('){
                return 0;
            }
        }
        else if(ch == '}'){
            if(!isStackEmpty(s) && pop(s) != '{'){
                return 0;
            }
        }
        else if(ch == ']'){
            if(!isStackEmpty(s) && pop(s) != '['){
                return 0;
            }
        }
        else if(ch == '(' || ch == '{' || ch == '['){
            push(s,ch);
        }
        else{
            continue;
        }
    }
    if(isStackEmpty(s)){
        return 1;
    }
    else{
        printf("Not Valid Parenthesis\n");
        return 0;
    }
}

int main(){

    struct stack *s;
    char exp[7];
    fgets(exp,(7),stdin);
    exp[strcspn(exp,"\n")] = 0;
    if(paren(s,exp)){
        printf("Valid Parenthesis\n");
    }
    return 0;
}
