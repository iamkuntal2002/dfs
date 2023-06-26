#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int helper(TreeNode *root,int mn,int mx){
        if(root == NULL) return abs(mx-mn);
        mx = max(root->val,mx);
        mn = min(mn,root->val);
        return max(helper(root->left,mn,mx),helper(root->right,mn,mx));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) return 0;
        return helper(root,INT_MAX,INT_MIN);
    }
};