#include<stdio.h>

int printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void insertionSort(int*arr,int n){
    for(int i=0;i<n-1;i++){
        int j=i+1;
        while(arr[j]<arr[j-1] && j>=1){
            //swap
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;

            j--;
        }
    }
    printArr(arr,n);
}

int main (){
    int arr[9];
    int n=9;

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    insertionSort(arr,n);


    return 0;
}