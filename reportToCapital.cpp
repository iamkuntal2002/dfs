#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/
class Solution {
public:
        long long dfs(vector<int> graph[], vector<bool>& visited, long long &ans, int curr, long long &seats){
        long long ppl = 1;
        visited[curr] = true;
        for(int v : graph[curr]){
            if(!visited[v]) ppl += dfs(graph,visited,ans,v,seats);
        }
        if(curr!=0){
            ans += ((ppl+seats-(long long)1)/seats);
        }
        return ppl;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> graph[n+1];
        vector<bool>visited(n+1,false);
        for(auto &i : roads){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        long long ans = 0, seat=seats;
        dfs(graph,visited,ans,0,seat);
        return ans;
    }
};