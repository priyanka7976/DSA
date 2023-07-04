#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// 1 Difference utility -> find difference between two strings
/*
int DiffUtility(string s1,string s2, int m, int n,vector<vector<int>>memo){
    if(memo[m][n]!=-1)
        return memo[m][n];
    if(m==0|| n==0)
        return 0;
    else{
        if(s1[m-1]==s2[n-1])
            memo[m][n]= 1+DiffUtility(s1,s2,m-1,n-1,memo);
        else{
            memo[m][n]=max(DiffUtility(s1,s2,m-1,n,memo),DiffUtility(s1,s2,m,n-1,memo));
        }
    }
    return memo[m][n];
}

// 2 Minimun insertion and deletion to convert string 1 to string 2
int MinID(string s1,string s2, int m, int n,vector<vector<int>>memo){
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    for(int i=0;i<=n;i++)
        dp[0][i]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

// 3) Shrtest common supersubsequence
int SCS(string s1,string s2, int m, int n,vector<vector<int>>memo){
    if(memo[m][n]!=-1)
        return memo[m][n];
    if(m==0 || n==0)
        return 0;
    else{
        if(s1[m-1]==s2[n-1])
            memo[m][n]=1+SCS(s1,s2,m-1,n-1,memo);
        else    
            memo[m][n]=max(SCS(s1,s2,m-1,n,memo),SCS(s1,s2,m,n-1,memo));
    }
    return memo[m][n];
}

// 4) Longest Palindrome geeks -> 2(ee)
int LongestPalindrome(string s1, int m,vector<vector<int>>memo){
    string s2=s1;
    reverse(s2.begin(),s2.end());
    return SCS(s1,s2,m,m,memo);
}


// 5) Longest repeating subsequence 
s1 = aabb o/p=2;
s1=asd o/p=0
int LCS(string s1,string s2,int m,int n,vector<vector<int>>memo){
    if(memo[m][n]!=-1)
        return memo[m][n];
    if(m==0 || n==0)
        return 0;
    else{
        if(s1[m-1]==s2[n-1] && m!=n)
            memo[m][n]=1+LCS(s1,s2,m-1,n-1,memo);
        else
            memo[m][n]=max(LCS(s1,s2,m-1,n,memo),LCS(s1,s2,m,n-1,memo));
    }
    return memo[m][n];
}
int LongestReapeting(string s1,int m,vector<vector<int>>memo){
    int lcs=LCS(s1,s1,m,m,memo);
    return lcs;
}
*/
// 6) Printing LCS of strings
string st="";
int PrintingLCS(string s1,string s2, int m, int n,vector<vector<int>>memo){
    if(memo[m][n]!=-1)
        return memo[m][n];
    if(m==0 ||n==0)
        return 0;
    else{
        if(s1[m-1]==s2[n-1]){
            st+=s1[m-1];
            memo[m][n]=1+PrintingLCS(s1,s2,m-1,n-1,memo);
        }
        else
            memo[m][n]=max(PrintingLCS(s1,s2,m-1,n,memo),PrintingLCS(s1,s2,m,n-1,memo));
    }
    return memo[m][n];
}


int main(){
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    vector<vector<int>>memo(m+1,vector<int>(n+1,-1));
    // int lcs=DiffUtility(s1,s2,m,n,memo);
    // cout<<"extra elements in string 1 is : "<<s1.length()-lcs; 
    
    // int lcs=MinID(s1,s2,m,n,memo);
    // cout<<"Minium operation of insertion or deletion to convert s1 to s2 : "<<n+m-2*lcs;

    // int lcs = SCS(s1,s2,m,n,memo);
    // cout<<n+m-lcs;

    // cin>>s1;
    // int m=s1.length();
    // vector<vector<int>>memo(m+1,vector<int>(m+1,-1));
    // cout<<LongestPalindrome(s1,m,memo);

    // cout<<LongestReapeting(s1,m,memo);

    PrintingLCS(s1,s2,m,n,memo);
    cout<<st;
    return 0;
}