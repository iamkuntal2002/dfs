#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
vector<int> leftView(TreeNode *root)
{
   // Your code here
   //simple dfs solution
   vector<int> res;
   if(root == NULL) return res;
   queue<TreeNode*> qu;
   qu.push(root);
   while(!qu.empty()){
       int size = qu.size();
       for(int i =0;i<size;i++){
           TreeNode *node = qu.front();
           qu.pop();
           if(i == 0) res.push_back(node->val);
           if(node->left != NULL) qu.push(node->left);
           if(node->right != NULL) qu.push(node->right);
       }
   }
   return res;
}