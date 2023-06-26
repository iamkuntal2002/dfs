#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    void levelorderTraversal(TreeNode *root, vector<vector<int>> &st){
        if(root== NULL ) return;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            vector<int> temp;
            for(int i =0;i<size;i++){
                TreeNode * node = qu.front();
                qu.pop();
                if(node->left != NULL) qu.push(node->left);
                if(node->right != NULL) qu.push(node->right);
                temp.push_back(node->val);            
            }
            st.push_back(temp);        
        }
    }
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> lvl;
        levelorderTraversal(root,lvl);
        vector<int> res;
        for(auto &v : lvl){
            int max = *max_element(v.begin(),v.end());
            res.push_back(max);
        }
        return res;
    }
};
class Solution2 {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            // TreeNode *node = qu.front();
            // qu.pop();
            int mx = INT_MIN;
            int size = qu.size();
            for(int i =0;i<size;i++){
                TreeNode *node =qu.front();
                qu.pop();
                mx = max(mx,node->val);
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right); 
            }
            res.push_back(mx);
        }
        return res;
    }
};