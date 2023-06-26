#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-duplicate-subtrees/

  struct TreeNode1 {
      int val;
      TreeNode1 *left;
      TreeNode1 *right;
      TreeNode1() : val(0), left(nullptr), right(nullptr) {}
      TreeNode1(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode1(int x, TreeNode1 *left, TreeNode1 *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    string helper(TreeNode1 *root,unordered_map<string,vector<TreeNode1*>> &mp){
        if(root == NULL) return "";
        string s = "(";
        s += helper(root->left,mp);
        s += to_string(root->val);
        s += helper(root->right,mp);
        s += ")";
        mp[s].push_back(root);
        return s;
    }
    vector<TreeNode1*> findDuplicateSubtrees(TreeNode1* root) {
        unordered_map<string,vector<TreeNode1*>> mp;
        vector<TreeNode1*> res;
        if(root == NULL) return res;
        helper(root,mp);
        for(auto pr : mp){
            // cout<<pr.first<<" "<<pr.second[0]->val<<endl;
            if(pr.second.size() >1){
                res.push_back(pr.second[0]);
            }
        }
        return res;
    }
};

//coding ninja
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

string helper(TreeNode<int> *root,unordered_map<string,int> &mp,vector<int> &ans){
    if(root == NULL) return "";
    string s = "(";
    s += helper(root->left,mp,ans);
    s += helper(root->right,mp,ans);
    s += to_string(root->data);
    s += ")";
    if(mp.find(s) != mp.end() && mp[s] == 1)
        ans.push_back(root->data);
    mp[s]++;
    return s;
}
vector<int> duplicateSubtrees(TreeNode<int> *root)
{
    //    Write your code here.
    unordered_map<string,int> mp;
    vector<int> ans;
    if(root == NULL) return ans;
    helper(root,mp,ans);
    if(ans.empty()) return {-1};
    return ans;
}
