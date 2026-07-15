#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define m 100
typedef struct list{
  int data;
  struct list *next;
}list;

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
int evaluation(char exp[100]){

    stack stack ;
    stack.top = -1;
    int i, op1, op2;

    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // If digit, push to stack
        if (ch >= '0' && ch <= '9') {
            push(&stack, ch - '0');  // convert char to int
        }
        // If operator, pop two operands and apply
        else {
            op2 = pop(&stack);
            op1 = pop(&stack);
            switch (ch) {
                case '+': push(&stack, op1 + op2); break;
                case '-': push(&stack, op1 - op2); break;
                case '*': push(&stack, op1 * op2); break;
                case '/': push(&stack, op1 / op2); break;
                case '^': {
                    int result = 1;
                    for (int j = 0; j < op2; j++)
                        result *= op1;
                    push(&stack, result);
                    break;
                }
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
        }
    }
    return pop(&stack);
}

// Driver code
int main() {
    char postfix[m];
    printf("Enter a postfix expression: ");
    scanf("%s", &postfix);

    int result = evaluation(postfix);
    printf("Result = %d\n", result);

    return 0;
}
   