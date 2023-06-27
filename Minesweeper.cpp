#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minesweeper/
class Solution {
public:
    bool isvalid(int n,int m,int x,int y){
        if(x<0 || y<0 || x>=n || y>= m) return false;
        return true;
    }
    void dfs(vector<vector<char>> &board,int x,int y,int &n,int &m){
        if(!isvalid(n,m,x,y)) return;
        
        if(board[x][y] == 'E'){
            int count = 0;
            if(isvalid(n,m,x,y+1) && board[x][y+1] == 'M') count++;
            if(isvalid(n,m,x,y-1) && board[x][y-1] == 'M') count++;
            if(isvalid(n,m,x+1,y) && board[x+1][y] == 'M') count++;
            if(isvalid(n,m,x-1,y) && board[x-1][y] == 'M') count++;
            if(isvalid(n,m,x+1,y+1) && board[x+1][y+1] == 'M') count++;
            if(isvalid(n,m,x+1,y-1) && board[x+1][y-1] == 'M') count++;
            if(isvalid(n,m,x-1,y+1) && board[x-1][y+1] == 'M') count++;
            if(isvalid(n,m,x-1,y-1) && board[x-1][y-1] == 'M') count++;


            if(count >0) 
                board[x][y] = '0'+count;
            else{
                board[x][y] = 'B';
                dfs(board,x,y+1,n,m);
                dfs(board,x,y-1,n,m);
                dfs(board,x+1,y,n,m);
                dfs(board,x-1,y,n,m);
                dfs(board,x+1,y+1,n,m);
                dfs(board,x+1,y-1,n,m);
                dfs(board,x-1,y+1,n,m);
                dfs(board,x-1,y-1,n,m);
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        int n = board.size();
        int m = board[0].size();
        dfs(board,click[0],click[1],n,m);
        return board;
    }
};
/*
["E","E","E","E","E"]
["E","E","M","E","E"]
["E","E","E","E","E"]
["E","E","E","E","E"]


["B","1","E","1","B"]
["B","1","M","1","B"]
["B","1","1","1","B"]
["B","B","B","B","B"]
*/