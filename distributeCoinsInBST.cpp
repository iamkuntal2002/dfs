#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/distribute-coins-in-binary-tree
// https://practice.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1
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
    void helper(TreeNode *parent, TreeNode *child, int &ans){
        if(child == NULL) return;
        helper(child,child->left,ans);
        helper(child,child->right,ans);
        if(child->val >1){
            int extra= child->val -1;
            child->val = 1;
            parent->val += extra;
            ans += extra;
        }
        else if(child->val <1){
            int needed = 1+ abs(child->val);
            child->val = 1;
            parent->val -= needed;
            ans += needed;
        }
    }
    int distributeCoins(TreeNode* root) {
        int ans =0;
        helper(root,root,ans);
        return ans;
    }
};


class GFGSolution
{
    public:
    int helper(TreeNode *root,int &ans){
        if(root == NULL) return 0;
        int left = helper(root->left,ans);
        int right = helper(root->right,ans);
        ans += abs(left) + abs(right);
        return (left + right + root->val -1);
    }
    int distributeCandy(TreeNode* root)
    {
        //code here
        if(root == NULL) return 0;
        int ans = 0;
        helper(root,ans);
        return ans;
    }
};