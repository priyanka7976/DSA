/*  1) When find sum of array with no adjacent elements
// i/p = [1 9 4 2] 
o/p=11
 include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* Reursive
int MaxSumNonAdj(int n, int arr[]){
    if(n==0)
        return arr[0];
    if(n<0)
        return 0;
    int pick=arr[n]+MaxSumNonAdj(n-2,arr); 
    int Notpick =MaxSumNonAdj(n-1,arr); 
    return max(pick,Notpick);
}


// Memoization
int MaxSumNonAdj(int n, int arr[], vector<int>&dp){
    if(n==0)
        return dp[0]=arr[0];
    if(n<0)  
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    int pick = arr[n]+MaxSumNonAdj(n-2, arr, dp);
    int notpick = MaxSumNonAdj(n-1, arr, dp);
    dp[n]=max(pick,notpick);
    return dp[n];
}

Tabulation
int MaxSumNonAdj(int n, int arr[]){
    vector<int>dp(n+1);
    dp[0]=arr[0];
    // int pick=0,notpick=0;
    for(int i=1;i<=n;i++){
        int notpick=dp[i-1];
        int pick=arr[i];
        if(i>1)
            pick+=dp[i-2];
        dp[i]=max(pick,notpick);
        // cout<<dp[i]<<endl;
    }
    return dp[n];
    // return 0;
}


// Space Optimization
int MaxSumNonAdj(int n, int arr[]){
    int prev=arr[0],prev2,curr;
    int pick,notPick;
    prev2=arr[0];
    for(int i=1;i<=n;i++){
        pick=arr[i];
        if(i>1)
            pick+=prev2;
        notPick=prev;
        curr=max(pick,notPick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // vector<int>dp(n+1,-1);
    // cout<<MaxSumNonAdj(n-1,arr,dp);
    cout<<MaxSumNonAdj(n-1,arr);
    return 0;
}
*/

// 2) find maximum sum of an array with no adjacent elements can be selected and first and last select together
