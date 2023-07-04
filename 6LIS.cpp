// Longest increaing subsequence
// arr[]={3_,4_,2,8_,10_} o/p=4

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


/*
int LIS(int arr[], int n){
    int list[n+1];
    list[0]=1;
    for(int i=1;i<n;i++){
        list[i]=1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                list[i]=max(list[i],list[j]+1);
                // cout<<"hii";
            }
        }
        // cout<<list[i]<<" ";
    }
    cout<<endl;
    int res=list[0];
    for(int i=1;i<n;i++){
        // cout<<list[i]<<" ";
        res=max(list[i],res);
    }
    return res;
}
*/

int ceilIndex(int tail[],int x,int l,int r){
    while(l<r){
        int m=(l+r)/2;
        if(tail[m]>=x)
            r=m;
        else    
            l=m-1;
    }
    return r;
}

int LIS(int arr[], int n){
    int tail[n];
    tail[0]=arr[0];
    int len=1;
    for(int i=1;i<n;i++){
        if(arr[i]>tail[len-1]){
            tail[len]=arr[i];
            len++;
        }
        else{
            int ceil=ceilIndex(tail,arr[i],0,len-1);
            tail[ceil]=arr[i];
        }
    }
    return len;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<LIS(arr,n);
    return 0;
}