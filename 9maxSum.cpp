#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int maximumSum(int arr[], int n){
    if(n==0)
        return arr[0];
    if(n<0)
        return 0;
    int pick=arr[n]+maximumSum(arr,n-2);
    int notPick = maximumSum(arr,n-1);
    int res= max(pick,notPick);
    return res;
}

int main(){
    int n,x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int temp1[n-1],temp2[n-1];
    int j=0,k=0;
    for(int i=0;i<n;i++){
        if(i!=0) {
            temp1[j]=arr[i];
            j++;
        }
        if(i!=n-1){
            temp2[k]=arr[i];
            k++;
        }
    }
    int res1=maximumSum(temp1,n-2);
    int res2=maximumSum(temp2,n-2);
    int res=max(res1,res2);
    cout<<res;
    return 0;
}
