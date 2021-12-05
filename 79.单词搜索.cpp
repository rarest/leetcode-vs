/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    void backTracing(vector<vector<char>> &board, vector<vector<bool>> &visited,  bool &find, int i, int j, int pos, const string &word) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return;
        }
        if(find || visited[i][j] || board[i][j] != word[pos]) {
            return;
        }
        if(pos == word.size() - 1) {
            find = true;
            return;
        }
        visited[i][j] = true;
        int xys[] = {0, 1, 0, -1, 0};
        for(int k = 0; k < 4; k++) {
            int x = i + xys[k]; 
            int y = j + xys[k+1];
            backTracing(board, visited, find, x, y, pos + 1, word);            
        }
        visited[i][j] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j){
                backTracing(board, visited, find, i, j, 0, word);
            }
        }
        return find;
    }
};
// @lc code=end

