#include<stdlib.h>
#include<stdio.h>
int partition(int arr[],int lb,int ub){
    int pivot = arr[lb];
    int start = lb,end = ub;
    while(start < end){
        while(start <= ub && pivot >= arr[start]){
            start++;
        }
        while(end >= lb && pivot < arr[end]){
            end--;
        }
        if(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    return end;
}
void quicksort(int arr[],int low, int high){
    if(low <high){
        int loc = partition(arr,low,high);
        quicksort(arr,low,loc-1);
        quicksort(arr,loc+1,high);
    }
}
int main(){
    int arr[20] = {1 ,17, 21, 42, 24, 27, 32 ,35, 45, 47 ,57 ,23 ,66 ,69, 70 ,76, 87, 85, 95 ,99};
    quicksort(arr,0,19);
    printf("The sorted array is:");
    for(int i=0;i<20;i++){
            printf("%d ",arr[i]);
    }
    return 0;
}