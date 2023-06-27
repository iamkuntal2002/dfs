#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/recover-binary-search-tree/

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
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = new TreeNode(INT_MIN);
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        if(first == NULL && prev->val >root->val) first = prev;
        if(first != NULL && prev->val > root->val) second = root;
        prev = root;
        inorder(root->right);
    }
    void swap(TreeNode *fir , TreeNode *sec){
        int temp = fir->val;
        fir->val = sec->val;
        sec->val = temp;
    }
    void recoverTree(TreeNode* root) {
        if(root == NULL) return;
        inorder(root);
        swap(first,second);
    }
};