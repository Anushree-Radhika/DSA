#include<stdio.h>
#include<stdlib.h>
int count = 0;
void merge(int arr[],int low,int mid,int high,int ans[]){

        int i = low,j=mid+1,k = low;
        while(i <= mid && j <= high){
                if(arr[i] < arr[j]){
                        ans[k] = arr[i];i++;
                }
                else{
                        ans[k] = arr[j];j++;
                }
                k++;
        }
        while(i <= mid){
                ans[k] = arr[i];
                k++;i++;
        }
        while(j <= high){
                ans[k] = arr[j];k++;j++;
        }
        for (int x = low; x <= high; x++) {
                arr[x] = ans[x];
        }
        return ;
}
void divide(int arr[],int low,int high,int ans[]){
        int mid = (low + high)/2;
        if(low < high){
                divide(arr,low,mid,ans);
                divide(arr,mid+1,high,ans);
                merge(arr,low,mid,high,ans);
        } 
        return ;   
}
int main(){
        int arr[20] = {1, 16, 12, 26, 25, 35, 33, 58, 45, 42, 56, 67 ,83, 75, 74, 86, 81, 88, 99, 95};
        int *ans = (int *)malloc(sizeof(int)*(20));
        divide(arr,0,19,ans);
        printf("The sorted array is:");
        for(int i=0;i<20;i++){
                printf("%d ",ans[i]);
        }
        return 0;
}