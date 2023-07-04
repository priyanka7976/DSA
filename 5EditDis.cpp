#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* Memoization
int EditDistance(string s1, string s2, int m, int n){
    if(m==0)
        return n;
    if(n==0)
        return m;
    else{
        if(s1[m-1]==s2[n-1])
            return EditDistance(s1,s2,m-1,n-1);
        else{ 
            int mini = min(EditDistance(s1,s2,m-1,n),EditDistance(s1,s2,m,n-1));
            return 1+min(mini, EditDistance(s1,s2,m-1,n-1));
        }
    }
}

Tabulation
*/
int EditDistance(string s1, string s2, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    for(int i=0;i<=n;i++)
        dp[0][i]=i;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else{
                int mini = min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=1+min(mini,dp[i-1][j-1]);
            }
            // cout<<dp[i][j]<<" ";
        }
    }
    cout<<endl;
    return dp[m][n];
}


int main(){
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    cout<<EditDistance(s1,s2,m,n);
    return 0;
}