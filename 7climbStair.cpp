#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* Recursive
int climbStair(int n){
    if(n==0)    
        return 1;
    if(n==1)
        return 1;
    int left = climbStair(n-1);
    int right= climbStair(n-2);
    return left+right;
}


Memoizaton
int climbStair(int n, vector<int>&dp){
    if(n==0 || n==1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    int left=climbStair(n-1,dp);
    int right=climbStair(n-2,dp);
    dp[n]=left+right;
    return dp[n];
}

Tabulation
int climbStair(int n){
    vector<int>dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
*/

int climbStair(int n){
    int prev=1;
    int curr;
    int prev2=1;
    for(int i=2;i<=n;i++){
        curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    cout<<climbStair(n);
    // vector<int>dp(n+1,-1);
    // cout<<climbStair(n,dp);
    return 0;
}