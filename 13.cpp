// Chocolate Pickup
// https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;


//recursive
int maxChoco(vector<vector<int>> &grid,int i,int j1,int j2,int r,int c){
    if(j1<0 || j1>=c || j2<0 || j2>=c)
        return -1e8;
    if(i==r-1){
        if(j1==j2)
            return grid[i][j1];
        else
            return grid[i][j1]+grid[i][j2];
    }
    int maxi=0,res;
    for(int dj1=-1;dj1<2;dj1++){
        for(int dj2=-1;dj2<2;dj2++){
            if(j1==j2)
                res=grid[i][j1]+maxChoco(grid, i+1, j1+dj1, j2+dj2,r,c);
            else
                res=grid[i][j1]+grid[i][j2]+maxChoco(grid, i+1, j1+dj1, j2+dj2,r,c);
            maxi=max(maxi,res);
        }
    }
    return maxi;
}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    int i=0,j1=0,j2=c-1;
    maxChoco(grid,i,j1,j2,r,c);
}

// memoization