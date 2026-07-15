#include<stdio.h>
#define maxi 18
typedef struct stack {
    int count;
    int elem[maxi];
}s;

void initialize(struct stack *s) {
    s = (struct stack*)malloc(sizeof(struct stack));
    s->count = -1;
}
int evaluatePostFix(char str[maxi]){

    int i=0;
    while(str[i] != '\0'){

        if(str[i] >= 'a' && str[i] <= 'z'){
            s->push(str[i]);
        }
        else if(str == ')'){

        }
        else{

        }
        i++;
    }
}

int size(struct stack * s) {
    return s->count + 1;
}
int isFull(struct stack * s) {
    if(s->count+1 == maxi) {
        return 1; 
    }
    return 0;
}
int main(){

    char str[maxi];
    fgets(str, maxi, stdin);
    getchar();
    printf("The string entered is:");
    printf("%s", str);
    evaluatePostFix();

}
