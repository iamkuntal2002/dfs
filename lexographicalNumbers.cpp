#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/lexicographical-numbers/
class Solution {
public:
    void helper(int i,int n,vector<int> &res){
        if(i>n) return;
        res.push_back(i);
        for(int j =0;j<10;j++){
            // res.push_back(i*10+j);
            helper(i*10+j,n,res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        if(n ==1){
            res.push_back(1);
            return res;
        }
        for(int i =1;i<=9;i++){
            helper(i,n,res);
        }
        return res;
    }
};