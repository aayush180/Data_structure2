#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;

    for(int i=0;i<=n;i++){
       ans=ans|i;
    }
    cout<<ans<<endl;
}