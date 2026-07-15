#include<stdio.h>
#include<stdlib.h>
int main(){

    int n;
    printf("Input the value of the 2D matrix size:");
    scanf("%d",&n);
    int arr[n][n],ans[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int ch;
            printf("Input an integer:");
            scanf("%d",&ch);
            arr[i][j] = ch;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-1-i] = arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            printf("%d ",ans[i][j]);
        }
    }
    return 0;
}
