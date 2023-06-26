#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/battleships-in-a-board/
class Solution {
public:
    bool isvalid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    void dfs(vector<vector<char>> &board,int i,int j,int n,int m){
        board[i][j] = '#';
        if(isvalid(i,j+1,n,m) && board[i][j+1] == 'X') dfs(board,i,j+1,n,m);
        if(isvalid(i,j-1,n,m) && board[i][j-1] == 'X') dfs(board,i,j-1,n,m);
        if(isvalid(i+1,j,n,m) && board[i+1][j] == 'X') dfs(board,i+1,j,n,m);
        if(isvalid(i-1,j,n,m) && board[i-1][j] == 'X') dfs(board,i-1,j,n,m);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j] == 'X'){
                    ans++;
                    dfs(board,i,j,n,m);
                }
            }
        }
        return ans;
    }
};