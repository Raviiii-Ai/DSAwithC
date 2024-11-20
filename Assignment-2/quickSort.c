#include<stdio.h>


int printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

  //partition
int partition(int *arr,int si,int ei){
    int i=si-1;
    int pivot=arr[ei];
    for(int j=si;j<ei;j++){
        if(arr[j]<=pivot){
            i++;
            //swap
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
     i++;

        //swap
        int temp=arr[i];
        arr[i]=arr[ei];
        arr[ei]=temp;

        return i;
  
}



  //quick sort
void quickSort(int *arr,int si,int ei){
    if(si>=ei){
        return;
    }
    int pivotIdx=partition(arr,si,ei);
    quickSort(arr,si,pivotIdx-1);//left
    quickSort(arr,pivotIdx+1,ei);//right


}

int main (){
    int arr[9];
    int n= sizeof(arr)/sizeof(arr[0]);
    int si=0;
    int ei=n-1;

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    quickSort(arr,si,ei);
      printArr(arr,n);




    return 0;
}