#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-univalue-path/description/
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
    int ans;
    int helper(TreeNode *root, int val){
        if(root == NULL) return 0;
        int left = helper(root->left,root->val);
        int right= helper(root->right,root->val);
        ans = max(ans,left+right);
        if(root->val == val) return max(left,right) +1;
        else return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        ans =0;
        if(root == NULL) return ans;
        helper(root,root->val);
        return ans;
    }
};