#include<stdio.h>

//Binary Search Function
int binarySearch(int arr[],int n,int value){
    int start=0;
    int end=n-1;
    
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==value){
            return mid;
        }
        else if(arr[mid]<value){
            start=mid+1;
        }
        else{
            end=mid-1;
        }

    }
    return -1;
    
}

int main (){
    int arr[9];
    int n=9;
    for(int i=0;i<9;i++){
        scanf("%d",&arr[i]);
    }

    int value;
    printf("enter value:");
    scanf("%d",&value);

    int output=binarySearch(arr,n,value);
    printf("%d",output);
    
    

}