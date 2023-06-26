#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/where-will-the-ball-fall/
class Solution {
public:
bool valid(int rsize,int csize,int r,int c){
        if(rsize<=r||csize<=c||c<0||r<0)return false;
        return true;
    }
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(r==grid.size())return c;
        if(valid(grid.size(),grid[0].size(),r,c)){
            if(grid[r][c]==1){
                if(valid(grid.size(),grid[0].size(),r,c+1)&&grid[r][c+1]==1){
                    return dfs(grid,r+1,c+1);
                }
            }else{
                if(valid(grid.size(),grid[0].size(),r,c-1)&&grid[r][c-1]==-1){
                    return dfs(grid,r+1,c-1);
                }
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m);
        for(int i =0;i<m;i++){
            int colreach = dfs(grid,0,i);
            ans[i] = colreach;
        }
        return ans;
    }
};