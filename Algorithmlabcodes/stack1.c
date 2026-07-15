#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define m 100
typedef struct stack{
    int top;
    int arr[m];
}stack;

void push(stack *stack, int val) {
    if (stack->top == m - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->arr[++(stack->top)] = val;
}
int pop(stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->arr[(stack->top)--];
}


stack evaluation(char exp[100]){


    stack st ;
    st.top = -1;
    int i;
    stack prefixStr;
    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if(ch == ')'){
            push(&prefixStr,pop(&st));
        }
        else if(ch >= 'a' && ch <= 'z'){
            push(&prefixStr, ch); 
        }
        else if(ch == '('){
            continue;
        }
        else {
            push(&st, ch);
        }
    }
    while(st.top != -1){
        push(&prefixStr,pop(&st));
    }
    return prefixStr;
}

// Driver code
int main() {
    char postfix[m];
    printf("Enter a postfix expression: ");
    scanf("%s", &postfix);

    stack result = evaluation(postfix);
    printf("Result = %d\n", result);

    return 0;
}
