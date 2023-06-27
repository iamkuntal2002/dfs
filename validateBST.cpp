#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool helper(TreeNode *root,int left,int right){
        if(root == NULL) return true;
        if(root->val <= left || root->val >= right) return false;
        return helper(root->left,left,root->val) && helper(root->right,root->val,right);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        return helper(root,INT_MIN,INT_MAX);
    }
};