#include<stdio.h>
#include<stdlib.h>
void insertionsort(int arr[]){
    int count = 0;
    for(int i=0;i<20;i++){
        for(int j = 19;j>=i;j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                count++;
                for(int k=0;k<20;k++){
                    printf("%d ",arr[k]);
                }
                printf("\n");
            }
        }
    }
    printf("The sorted array is:");
    for(int i=0;i<20;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("%d is the number of swaps that happened in bubble sort algo\n",count);
    return ;
}
void avoidswapIS(int arr[]){
    int count = 0;
    for(int i=0;i<20;i++){
        int max = arr[i];
        for(int j = 19;j>=i;j--){
            if(arr[j] < max){
                arr[j] = arr[j-1];
                count++;
                for(int k=0;k<20;k++){
                    printf("%d ",arr[k]);
                }
                printf("\n");
            }
            else{
                arr[j-1] = max;
                max = arr[j];
            }
        }
    }
    printf("The sorted array is:");
    for(int i=0;i<20;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("%d is the number of swaps that happened in bubble sort algo\n",count);
    return ;
}

int main(){
    int arr1[20] = {22 ,20, 81, 38 ,95, 84, 99, 12, 79, 44 ,26 ,87 ,96, 10 ,48 ,80 ,1 ,31 ,16 ,92};
    int arr2[20] = {1, 16, 12, 26, 25, 35, 33, 58, 45, 42, 56, 67 ,83, 75, 74, 86, 81, 88, 99, 95};
    printf("MENU\n");
    printf("1.Insertion Sort\n");
    printf("2.Avoid Swap\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:{
            insertionsort(arr1);
            break;
        }
        case 2:{
            avoidswapIS(arr2);
            break;
        }
        default:{
            printf("Invalid choice\n");
        }
    }
    return 0;
}