#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//Memoization

int Fib(int n,vector<int> &memo){
    if(memo[n]==-1){
        if(n==0 || n==1)
            memo[n]=n;
        else 
            memo[n]=Fib(n-1,memo)+Fib(n-2,memo);
    }
    return memo[n];
}
/*int Fib(int n){
    if(memo[n]==-1){
        if(n==0 || n==1)
            return n;
        else 
            memo[n]=Fib(n-1)+Fib(n-2);
    }
    return memo[n];
}*/

/*   Tabulation
int Fib(int n){
    int F[n+1];
    F[0]=0,F[1]=1;
    for(int i=2;i<=n;i++)
    {
        F[i]=F[i-1]+F[i-2];
    }
    return F[n];
}
*/
int main(){
    int n;
    cin>>n;
    vector<int> memo(n+1,-1);

    cout<<Fib(n,memo);
    return 0;
}