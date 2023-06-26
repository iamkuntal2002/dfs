#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/linked-list-in-binary-tree/
struct ListNode{
    int val;
    ListNode *next;
};
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
    bool helper(ListNode *head,TreeNode *root){
        if(head == NULL) return true;
        if(root == NULL) return false;
        if(head->val != root->val) return false;
        return helper(head->next,root->left) || helper(head->next,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == NULL) return true;
        if(root == NULL && head != NULL) return false;
        return helper(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};
