#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree
    
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
    int ans = 0;
    void helper(TreeNode *root,int left, int right){
        if(root == NULL) return;
        ans = max(ans,max(left,right));
        if(root->left) helper(root->left,right+1,0);
        if(root->right) helper(root->right,0,left+1);   
    }
    int longestZigZag(TreeNode* root) {
        // if(root == NULL || (root->left ==NULL && root->right == NULL)) return 0;
        helper(root,0,0);
        return ans;
    }
};