#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/all-paths-from-source-to-target
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int s, vector<vector<int>> &graph, vector<int> &path,int target){
        path.push_back(s);  //push s to path
        if(s == target) ans.push_back(path);
        else {
            for(int &i : graph[s])
                dfs(i,graph,path,target);   //call every possible path
        }
        path.pop_back();       //back to s, 
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size()-1;
        vector<int> path;
        dfs(0,graph,path,target);      //starting from the 0
        return ans;
    }
};