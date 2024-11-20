#include<stdio.h>


int printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void merge(int *arr,int si,int mid,int ei){
    int n1=mid-si+1;
    int n2=ei-mid;

    int arr1[n1];
    int arr2[n2];

    for(int i=0;i<n1;i++){
        arr1[i]=arr[si+i];
    }

    for(int j=0;j<n2;j++){
        arr2[j]=arr[mid+1+j];
    }

   int i,j,k;
   i=0;
   j=0;
   k=si;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr,int si,int ei){
    //baseCase
    if(si>=ei){
        return;
    }
    int mid= si+(ei-si)/2;

    //left call
    mergeSort(arr,si,mid);
    
    //right call
    mergeSort(arr,mid+1,ei);

    //merge both left and right part
    merge(arr,si,mid,ei); 
}

int main (){
    int arr[9];
    int n=9;
    int si=0;
    int ei=n-1;

    for(int t=0;t<n;t++){
        scanf("%d",&arr[t]);
    }
    
    mergeSort(arr,si,ei);
    printArr(arr,n);




    return 0;
}