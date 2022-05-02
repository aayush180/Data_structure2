#include<stdio.h>
#include<limits.h>

void Swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Bubble(int A[],int n)
{
   int flag=0;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(A[j] > A[j+1]){
             Swap(&A[j],&A[j+1]);
             flag=1;
            }
        }
        if(flag==0){
          break;
        }
    }
    if(flag==0){
        printf("Array is Sorted ");
    }
}

void Insert(int A[],int n){
  int i,j,x;
    for(i=1;i<n;i++){
         j=i-1;
         x=A[i];

         while(j >-1 && A[j]>x){
             A[j+1]=A[j];
             j--;
         }
         A[j+1]=x;
    }
}

void Selectsort(int A[],int n){
    int i,j,k;

    for(i=0;i<n-1;i++){

        for(j=k=i;j<n;j++){
            if(A[j] < A[k]){
                k=j;
            }
        }
        Swap(&A[i],&A[k]);
    }
}

int Partitation(int A[],int l,int h){
    int pivot=A[l];
    int i=l,j=h;
    
    do{
    do{
        i++;
    }while(A[i] < pivot);
    do{
        j--;
    }while(A[j] > pivot);

    if(i<j){
        Swap(&A[i],&A[j]);
    }
    }while(i<j);

    Swap(&A[l],&A[j]);
    return j;
}

void Quicksort(int A[],int l,int h){
    int j;
    if(l<h){
       j=Partitation(A,l,h);
       Quicksort(A,l,j);
       Quicksort(A,j+1,h);
    }
}

void Merge(int A[],int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    int B[100];

    while(i<=mid && j<=high){
        if(A[i]<=A[j]){
            B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }
    for(;i<=mid;i++){
        B[k++]=A[i];
    }
    for(;j<=high;j++){
        B[k++]=A[j];
    }
    for(i=low;i<=high;i++){
        A[i]=B[i];
    }
}

void IMerge(int A[],int n){
    int p,i,low,mid,high;

    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            low=i;
            high=i+p-1;
            mid=(low+high)/2;
            Merge(A,low,mid,high);
        }
    }
    if(p/2<n){
        Merge(A,0,p/2-1,n);
    }
}

void print(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

int main(){
    int A[]={3,6,2,4,1,5};
    int n=6;

   
    IMerge(A,n);
    print(A,n);

}