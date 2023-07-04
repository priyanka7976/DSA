/*LCS = longest common subsequence
s1="abcdgh" s2="afdfhr" -> o/p=3 (adh)
s1="xyz" s2="xyz" -> o/p=3
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* Memoization

int LCS(string s1,string s2,int m,int n,vector<vector<int>>memo){
    if(memo[m][n]!=-1){
        return memo[m][n];
    }
    if(m==0 || n==0)
        return 0;
    else{
        if(s1[m-1]==s2[n-1])
            memo[m][n]=1+LCS(s1,s2,m-1,n-1,memo);
        else{
            memo[m][n]=max(LCS(s1,s2,m-1,n,memo),LCS(s1,s2,m,n-1,memo));
        }
    }
    return memo[m][n];
}
*/

//Tabulation
int LCS(string s1,string s2,int m,int n,vector<vector<int>>memo){
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    for(int i=0;i<=m;i++)
        dp[0][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    vector<vector<int>>memo(m+1,vector<int>(n+1,-1));

    cout<<LCS(s1,s2,m,n,memo);    
    return 0;
}