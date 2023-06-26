#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/kth-smallest-element-in-a-bst

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 //with extra space
class Solution {
public:
    void inorder(TreeNode *root, vector<int> &store){
        if(root == NULL)
            return;
        inorder(root->left,store);
        store.push_back(root->val);
        inorder(root->right,store);
        }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> store;
        if(root == NULL) return 0;
        inorder(root,store);
        return store[k-1];
    }
};
//without extra space
class Solution {
public:
    int ans;
    void inorder(TreeNode* root, int &k ){
        if(root==NULL) return ; 
        inorder(root->left, k);
        k--;
        if(k==0) {
            ans = root->val;
            return; 
        }        
        inorder(root->right, k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};