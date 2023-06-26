#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/balance-a-binary-search-tree

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
    vector<TreeNode*> inorder;
    void inordertraversal(TreeNode *root){
        if(root == NULL) return;
        inordertraversal(root->left);
        inorder.push_back(root);
        inordertraversal(root->right);
    }
    TreeNode *balencing(int left, int right){
        if(right < left) return NULL;
        int mid = (left +right)/2;
        TreeNode* root = inorder[mid];
        root->left = balencing(left,mid-1);
        root->right = balencing(mid+1,right);
        return root;
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        inordertraversal(root);
        return balencing(0,inorder.size()-1);
        // return root;
    }
};