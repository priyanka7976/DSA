/* 1.) Find total number of path from which we can go from (0,0) to (m-1,n-1)
// ex -> m=2,n=2 so o/p=>2 ((0,0 -> 0,1 then 0,1->1,1) and (0,0 -> 1,0 then 1,0->1,1))
 
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

 Recursive
int FindPath(int m, int n){
    if(m==0 && n==0)
        return 1;
    if(n<0 || m<0)
        return 0;
    int left = FindPath(m,n-1);
    int right = FindPath(m-1,n);
    return left+right;
}


// Memoization
int path(int m,int n, vector<vector<int>>&dp){
    if(m==0 && n==0)
        return 1;
    if(m<0 || n<0)
        return 0;
    if(dp[m][n]!=-1)
        return dp[m][n];
    int left = path(m,n-1,dp);
    int up = path(m-1,n,dp);
    dp[m][n]=left+up;
    return dp[m][n];
}
int FindPath(int m, int n){
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return path(m,n,dp);
}


//Tabulation
int FindPath(int m, int n){
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 && j==0)
                dp[0][0]=1;
            else{
                int up=0,left=0;
                if(i>0)
                    up=dp[i-1][j];
                if(j>0)
                    left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[m][n];
}


int FindPath(int m, int n){
    vector<int>prev(n+1,0);
    vector<int>curr(n+1,0);
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 && j==0){
                curr[j]=1;
            }
            else{
                int up=0,left=0;
                if(i>0) up=prev[j];
                if(j>0) left=curr[j-1];
                curr[j]=left+up;
            }
        }
        prev=curr;
    }
    return prev[n];
}

int main(){
    int m,n;
    cin>>m>>n;
    cout<<FindPath(m-1,n-1);
    return 0;
}


2.) Find total number of path from which we can go from (0,0) to (m-1,n-1) if there is -1 then don't go in that box
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n=100;
int FindPath(vector<vector<int>>&arr,int m,int n){
    if(m==0 && n==0)
        return 1;
    if(m<0|| n<0)
        return 0;
    if(arr[m][n]==-1)
        return 0;
    int left=FindPath(arr,m,n-1);
    int right=FindPath(arr,m-1,n);
    return left+right;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int>(n,0));
    int a;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a;
            arr[i][j]=a;
        }
    }
    cout<<FindPath(arr,m-1,n-1);
    return 0;
}

