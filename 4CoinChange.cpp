// coin[]={1,2,3} sum=4
// o/p =4 {1+1+1+1, 1+1+2, 2+2, 1+3}

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
int CoinChange(int coin[], int n, int sum){
    if(sum==0)
        return 1;
    if(n==0)
        return 0;
    int res=CoinChange(coin,n-1,sum);
    if(coin[n-1]<=sum)
        res+=CoinChange(coin,n,sum-coin[n-1]);
    return res;
}
*/

int CoinChange(int coin[], int n, int sum){
    int dp[sum+1][n+1];
    for(int i=0;i<=n;i++)
        dp[0][i]=1;
    for(int i=0;i<=sum;i++)
        dp[i][0]=0;
    
    for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];
            if(coin[j-1]<=i)
                dp[i][j]+=dp[i-coin[j-1]][j];
        }
    }
    return dp[sum][n];
}

int main(){
    int n;
    cin>>n;
    int coin[n];
    for(int i=0;i<n;i++)
        cin>>coin[i];
    int sum;
    cin>>sum;
    cout<<CoinChange(coin,n,sum);
    return 0;
}