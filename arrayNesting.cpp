#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/array-nesting/
class Solution {
public:
    void dfs(vector<int> &nums,vector<bool> &vis,int &count,int ind){
        vis[ind] = true;
        if(ind>= nums.size()) return;
        count++;
        if(!vis[nums[ind]]) dfs(nums,vis,count,nums[ind]);
    }
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        vector<bool> vis(n,false);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                int count = 0;
                dfs(nums,vis,count,i);
                ans = max(ans,count);
            }
        }
        return ans;
    }
};