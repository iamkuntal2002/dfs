#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
   vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> res;
        queue<pair<Node*,int>> qu;
        map<int,int> mp;
        qu.push({root,0});
        while(!qu.empty()){
           
                Node * node = qu.front().first;
                int dist= qu.front().second;
                qu.pop();
                if(mp.find(dist) == mp.end()) mp[dist] = node->data;
                if(node->left != NULL) qu.push({node->left,dist-1});
                if(node->right != NULL) qu.push({node->right,dist+1});
            
        }
        for(auto pr : mp){
            res.push_back(pr.second);
        }
        return res;
    }

};