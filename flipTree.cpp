#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/flip-equivalent-binary-trees/

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
    bool helper(TreeNode *r1,TreeNode *r2){
        if(r1 == NULL && r2 == NULL) return true;
        if(r1 == NULL || r2 == NULL) return false;
        if(r1->val != r2->val) return false;
        bool left = helper(r1->left,r2->left) && helper(r1->right,r2->right);
        bool right = helper(r1->left,r2->right) && helper(r1->right,r2->left);
        return left || right;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) return false;
        return helper(root1,root2);
    }
};