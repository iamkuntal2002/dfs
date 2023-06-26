#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        vector<int> lvl;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            for(int i =0;i<size;i++){
                TreeNode *node = qu.front();
                qu.pop();
                lvl.push_back(node->val);
                if(node->left != NULL) qu.push(node->left);
                if(node->right != NULL) qu.push(node->right);
            }
        }
        return lvl.size();
    }
};