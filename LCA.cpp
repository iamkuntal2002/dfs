#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 //bt
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root->val == p->val || root->val == q->val) return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        if(left != NULL && right != NULL) return root;
        else{
            if(left == NULL) return right;
            else return left;
        }
    }
};

//bst
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val > p->val) && (root->val > q->val))
            return lowestCommonAncestor(root->left,p,q);
        if((root->val < p->val) && (root->val < q->val))
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};