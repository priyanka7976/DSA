/*
https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

 memoization
#include <bits/stdc++.h> 
using namespace std;

bool sum(int i, int target, vector<int> &arr,vector<vector<int>>&dp){
    if(target==0)
        return true;
    if(i==0)
        return (arr[0]==target);
    if(dp[i][target]!=-1)
        return dp[i][target];
    bool notTake = sum(i-1,target,arr,dp);

    bool take=false;
    if(target>=arr[i]) 
        take= sum(i-1,target-arr[i],arr,dp);
    return dp[i][target]=take||notTake;
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return sum(n-1,k,arr,dp);
}*/