#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> qu;
        if(root == NULL) return 0;
        qu.push(root);
        int ans = 0;
        int lvl = 1;
        int maxsum = INT_MIN;
        while(!qu.empty()){
            int currsum = 0;
            int size = qu.size();
            while(size--){
                TreeNode *node = qu.front();
                qu.pop();
                currsum += node->val;
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
            if(currsum > maxsum){
                ans = lvl;
                maxsum = currsum;
            }
            lvl++;
        }
        return ans;
    }
};