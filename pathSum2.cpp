#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/path-sum-ii

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
    void helper(TreeNode* root,int target,vector<vector<int>> &res,vector<int> curr){
        if(root == NULL) return;
        curr.push_back(root->val);
        if(root->val == target && root->left == NULL && root->right == NULL){
            res.push_back(curr);
            return;
        }
        if(root->left) helper(root->left,target-root->val,res,curr);
        if(root->right) helper(root->right,target-root->val,res,curr);
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        vector<int> curr;
        helper(root,target,res,curr);
        return res;
    }
};
