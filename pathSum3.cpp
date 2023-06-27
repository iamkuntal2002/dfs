#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/path-sum-iii/

  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    unordered_map<long long,int> mp;
    void helper(TreeNode *root,int &target,int &count,long long currsum){
        if(root == NULL) return;
        currsum += root->val;
        if(currsum == target) count++;
        if(mp.find(currsum-target) != mp.end()) count += mp[currsum-target];
        mp[currsum]++;
        helper(root->left,target,count,currsum);
        helper(root->right,target,count,currsum);
        mp[currsum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        helper(root,targetSum,count,0);
        return count;
    }
};