#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int *A,n,ch,x,i,j;
    printf("Enter The Dimension :");
    scanf("%d ",&n);

    A=new int[n];

    printf("1)Create\n2)Get\n3)Set\n4)Display\n");

    printf("Enter The Choise :");
    cin>>ch;

    switch (ch)
 {
    case 1:       //Create
        for(i=1;i<=n;i++){
            scanf("%d ",&A[i-1]);
        }
        break;
    case 2:      //Get
        printf("Enter Indices \n");
        scanf("%d %d",&i,&j);
        if(i == j){
            printf("%d ",A[i-1]);
        }
        else{
            printf("0 ");
        }
        break;
    case 3:     //Set
        printf("Enter Row Column & Element");
        scanf("%d %d %d ",&i,&j,&x);
        if(i == j)
        {
          A[i-1] = x;
        }
        break;
    case 4:     //Display
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i == j){
                    printf("%d ",A[i-1]);
                }
                else{
                    printf("0 ");
                }
            }
            printf("\n");
        }
        break;
 }


}