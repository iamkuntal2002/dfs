#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

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
    TreeNode *getLca(TreeNode *root,int p,int q){
        if(root == NULL) return NULL;
        if(root->val == p || root->val == q) return root;
        TreeNode *left = getLca(root->left,p,q);
        TreeNode *right = getLca(root->right,p,q);
        if(left != NULL && right != NULL) return root;
        else{
            if(left == NULL) return right;
            else return left;
        }
    }
    bool getPath(TreeNode *root,string &path,int val){
        if(root == NULL) return false;
        if(root->val == val) return true;
        path.push_back('L');
        if(getPath(root->left,path,val)) return true;
        path.pop_back();
        path.push_back('R');
        if(getPath(root->right,path,val)) return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int start, int dest) {
        if(root == NULL) return "";
        TreeNode *lca = getLca(root,start,dest);
        string lca_start = "";
        string lca_dest = "";
        getPath(lca,lca_start,start);
        getPath(lca,lca_dest,dest);
        for(auto &ch : lca_start) ch = 'U';
        return lca_start + lca_dest;
    }
};