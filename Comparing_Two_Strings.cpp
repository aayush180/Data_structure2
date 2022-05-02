
#include<stdio.h>

int CompString()
{
                                        // 0  1  2  3  4  5  6   7 
    char A[]={"Painted"};               //[p][a][i][n][t][e][d][\0]
    char B[]={"Painted"};
    int i,j;

   for(i=0,j=0;A[i]!='\0' && B[j]!='\0';i++,j++)
   {
       if(A[i] != B[j]){
          break;
       }
   }
   if(A[i] == B[j]){
       printf("Equal ");
   }
   else if (A[i] < B[j]){
       printf("Smaller ");
   }
   else{
       printf("Greater ");
   }
  
   
}

int main()
{
printf("%d ",CompString());
    
    
}