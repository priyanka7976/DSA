#include <bits/stdc++.h> 

int path(vector<vector<int>> &grid,int n,int m){
    if(m==0 && n==0)
        return grid[0][0];
    if(n<0 || m<0)
        return INT_MAX;
    int up = grid[n][m]+path(grid,n-1,m);
    int left = grid[n][m]+path(grid,n,m-1);
    int mini = min(up,left);
    return mini;
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int col,row;
    row=grid[0].size();
    col=grid.size();
    return path(grid,row-1,col-1);
}