#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/serialize-and-deserialize-bst

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Codec {
public:

    void inorder(TreeNode* root, string& order) {
        if (!root) return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars
        for (int i=0; i<4; i++) order.push_back(buf[i]);
        inorder(root->left, order);
        inorder(root->right, order);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string curr = "";
        inorder(root,curr);
        return curr;
    }

    TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
        if (pos >= buffer.size()) return NULL; //using pos to check whether buffer ends is better than using char* directly.
        
        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue) return NULL;
        
        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        node->left = reconstruct(buffer, pos, minValue, value);
        node->right = reconstruct(buffer, pos, value, maxValue);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       int pos = 0;
       return reconstruct(data,pos,INT_MIN,INT_MAX); 
    }
};
//copied

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;