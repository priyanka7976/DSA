// DP 12. Minimum/Maximum Falling Path Sum | Variable Starting and Ending Points | DP on Grids


#include <bits/stdc++.h> 
using namespace std;
int minPath(vector<vector<int>> &vec, int i,int j,int n, vector<vector<int>>&dp) {
    if (j < 0 || j >= n)
        return 1e9;
    if (i== 0)
        return dp[i][j]= vec[i][j];
    if(dp[i][j]!=-1)
        return dp[i][j];
    int s=vec[i][j]+minPath(vec,i-1,j,n,dp);
    int t=vec[i][j]+minPath(vec,i-1,j-1,n,dp);
    int p=vec[i][j]+minPath(vec,i-1,j+1,n,dp);
    dp[i][j]=min(s,min(t,p));
    return dp[i][j];
}

int minFallingPathSum(vector<vector<int>> &vec, int n) {
    // Write your code here.
    int res=1e9;
    for (int i = 0; i < n; i++) {
        vector<vector<int>>dp(n,vector<int>(n,-1));
      res = min(res,minPath(vec, n - 1, i,n,dp));
    }
    return res;
}


// 2 tabulation
#include <bits/stdc++.h> 
using namespace std;

int minFallingPathSum(vector<vector<int>> &vec, int n) {
    // Write your code here.
    int res=1e9;
    vector<vector<int>>dp(n,vector<int>(n,0));
    for (int i = 0; i < n; i++) {
      dp[0][i]=vec[0][i];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int lg=1e9,rg=1e9;
            int down=vec[i][j]+dp[i-1][j];
            if(j>0)
                lg=vec[i][j]+dp[i-1][j-1];
            if(j<=n-2)
                rg=vec[i][j]+dp[i-1][j+1];
            dp[i][j]=min(down,min(lg,rg));
        }
    }

    int mini=dp[n-1][0];
    for (int i = 1; i < n; i++) {
        mini=min(mini,dp[n-1][i]);
    }
    return mini;
}