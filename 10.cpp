#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* recursive 
int MaxDay(vector<vector<int>> arr,int day, int lastInd){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=lastInd)
                maxi = max(maxi,arr[0][i]);
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=lastInd){
            int point = arr[day][i]+MaxDay(arr,day-1,i);
            maxi=max(maxi,point);
        }
    }
    return maxi;
}

Memoization
int MaxDay(vector<vector<int>> arr,int day, int lastInd, vector<vector<int>> dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=lastInd)
                maxi = max(maxi,arr[0][i]);
        }
        return maxi;
    }
    if(dp[day][lastInd]!=-1)
        return dp[day][lastInd];
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=lastInd){
            int point=arr[day][i]+MaxDay(arr,day-1,i,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][lastInd]=maxi;
}
*/

int MaxDay(vector<vector<int>> arr,int day){
    vector<vector<int>> dp(day,vector<int>(4,0));
    dp[0][0]=max(dp[0][1],dp[0][2]);
    dp[0][1]=max(dp[0][0],dp[0][2]);
    dp[0][2]=max(dp[0][0],dp[0][1]);
    dp[0][3]=max(dp[0][1],max(dp[0][0],dp[0][2]));
    int maxi;
    for(int i=1;i<day;i++){
        for(int last=0;last<4;last++){
            maxi=0;
            dp[i][last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=arr[i][task]+dp[i-1][task];
                    maxi=max(maxi,point);
                }
            }
            dp[i][last]=maxi;
        }
    }
    return dp[day-1][3];
}


int main(){
    int days;
    cin>>days;
    int a,b,c;
    vector<vector<int>> arr(days,vector<int>(3));
    for(int i=0;i<days;i++){
        cin>>a>>b>>c;
        arr[i][0]=a;
        arr[i][1]=b;
        arr[i][2]=c;
    }
    //recursion
    // cout<<MaxDay(arr,days-1,3);

    //memoization
    // vector<vector<int>> dp(days,vector<int>(4,-1));
    // cout<<MaxDay(arr,days-1,3,dp);

    // tabulation
    cout<<MaxDay(arr,days);

    return 0;
}