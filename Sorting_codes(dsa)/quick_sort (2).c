#include<stdlib.h>
#include<stdio.h>
int median(int a, int b, int c) {
    if ((a > b) ^ (a > c)) return a;
    else if ((b > a) ^ (b > c)) return b;
    return c;
}
int partition(int arr[],int lb,int ub){
    int mid = (lb + ub) / 2;
    int pivot = median(arr[lb], arr[mid], arr[ub]);

    int i = lb;
    int j = ub;

    while(1) {
        while (arr[i] < pivot){
            i++;
        }
        while (arr[j] > pivot){
            j--;
        }

        if (i >= j) return j;

        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}
void quicksort(int arr[],int low, int high){
    if(low <high){
        int loc = partition(arr,low,high);
        quicksort(arr,low,loc-1);
        quicksort(arr,loc+1,high);
    }
}
int main(){
    // int arr[20] = {1 ,17, 21, 42, 24, 27, 32 ,35, 45, 47 ,57 ,23 ,66 ,69, 70 ,76, 87, 85, 95 ,99};
    int arr[4] = {4,3,2,1};
    quicksort(arr,0,4);
    printf("The sorted array is:");
    for(int i=0;i<4;i++){
            printf("%d ",arr[i]);
    }
    return 0;
}