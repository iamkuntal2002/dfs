#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-pruning/

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
    TreeNode *remove(TreeNode *root){
        if(root == NULL) return root;
        root->left = remove(root->left);
        root->right = remove(root->right);
        if(root->val == 1 || root->left != NULL || root->right != NULL) return root;
        else return NULL;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return remove(root);
    }
};