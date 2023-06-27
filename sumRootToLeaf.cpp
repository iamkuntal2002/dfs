#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int helper(TreeNode *root,int sum){
        if(root == NULL) return 0;
        sum = sum*10 + root->val;
        if(root->left == NULL && root->right == NULL) return sum;
        int leftsum = helper(root->left,sum);
        int rightsum = helper(root->right,sum);
        return (leftsum + rightsum);
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = 0;
        return helper(root,sum);
        // return sum;
    }
};