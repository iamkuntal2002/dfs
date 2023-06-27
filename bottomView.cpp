#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
struct Node{
    int data;
    Node *left,*right;
};
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> res;
        map<int,int> mp;
        queue<pair<Node*,int>> qu;
        if(root == NULL) return res;
        qu.push({root,0});
        while(!qu.empty()){
            Node *node = qu.front().first;
            int dist = qu.front().second;
            qu.pop();
            mp[dist] = node->data;
            if(node->left != NULL) qu.push({node->left,dist-1});
            if(node->right != NULL) qu.push({node->right,dist+1});
        }
        for(auto pr : mp){
            res.push_back(pr.second);
        }
        return res;
    }
};