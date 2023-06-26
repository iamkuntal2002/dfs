#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/convert-bst-to-greater-tree

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
    TreeNode* helper(TreeNode *root,int &sum){
        if(root == NULL) return root;
        helper(root->right,sum);
        sum += root->val;
        root->val = sum;
        helper(root->left,sum);
        return root;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return root;
        int sum = 0;
        return helper(root,sum);
    }
};