#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/employee-importance/

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    void dfs(unordered_map<int,Employee*> adj,int start,int &ans){
        ans += adj[start]->importance;
        for(auto adjnode : adj[start]->subordinates){
            dfs(adj,adjnode,ans);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        unordered_map<int,Employee*> adj;
        for(auto emp : employees){
            adj[emp->id] = emp;
        }
        int ans = 0;
        dfs(adj,id,ans);
        return ans;
    }
};