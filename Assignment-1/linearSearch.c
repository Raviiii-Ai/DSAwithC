#include<stdio.h>

//Linear Search Function
int linearSearch(int arr[],int n,int target){
for(int i=0;i<n;i++){
    if(arr[i]==target){
        return i;
    }  
}
return -1;
}

int main (){
  int arr[9];
    int n=9;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int target;
    printf("enter target value:");
    scanf("%d",&target);

    //final ans
    int ans=linearSearch(arr,n,target);
    printf("%d\n",ans);
    

  
 return 0;  
}



