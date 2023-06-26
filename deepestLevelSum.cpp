#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/deepest-leaves-sum/

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
    int deepestLeavesSum(TreeNode* root) {
       vector<vector<int>> level;
       queue<TreeNode*> qu;
       qu.push(root);
       while(!qu.empty()){
           int size = qu.size();
           vector<int> temp;
           for(int i =0;i<size;i++){
                TreeNode *node = qu.front();
                qu.pop();
                temp.push_back(node->val);
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
           }
           level.push_back(temp);
       } 
       int n = level.size();
       vector<int> lastlevel = level[n-1];
       int ans = 0;
       for(auto el : lastlevel) ans += el;
       return ans;
    }
};