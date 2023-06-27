#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-sub-islands/
class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &flag){
        if(i<0 || j<0 || i>= grid2.size() || j >= grid2[0].size()) return;
        if(grid2[i][j] == 0) return;
        if(grid2[i][j] == 1){
            if(grid1[i][j] == 0){
                flag = false;
                return;
            }
            grid2[i][j] = 0;
        }
        dfs(grid1,grid2,i+1,j,flag);
        dfs(grid1,grid2,i,j+1,flag);
        dfs(grid1,grid2,i,j-1,flag);
        dfs(grid1,grid2,i-1,j,flag);

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans =0;
        int m =grid1.size();
        int n = grid1[0].size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                bool flag = true;
                if(grid2[i][j] == 1){
                    dfs(grid1,grid2,i,j,flag);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};