/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    void backtracing(vector<vector<string>> & ans, vector<string> & board, vector<bool> &colum, vector<bool> &ldialog, vector<bool> & rdialog, int row, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(colum[i] || ldialog[row+i]||rdialog[n-1 + row -i])
                continue;
            colum[i] = ldialog[row+i] = rdialog[n-1 + row -i] =true;
            board[row][i]='Q';
            backtracing(ans, board, colum, ldialog, rdialog, row+1,n);
            board[row][i]='.';
            colum[i] = ldialog[row+i] = rdialog[n-1 + row -i] =false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        vector<bool> colum(n,false);
        vector<bool> ldialog(2*n-1, false);
        vector<bool> rdialog(2*n-1, false);
        backtracing(ans, board, colum, ldialog, rdialog, 0, n);
        return ans;
    }
};
// @lc code=end

