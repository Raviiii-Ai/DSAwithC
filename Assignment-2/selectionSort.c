#include<stdio.h>

int printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}

//selectionSort
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
            minIdx=j;
            } 
        }
          //swap
         int temp=arr[i];
            arr[i]=arr[minIdx];
            arr[minIdx]=temp;
    }
    printf("\n");
    printArr(arr,n);
}

int main (){
    int arr[9];
    int n=9;

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    selectionSort(arr,n);
    return 0;
}