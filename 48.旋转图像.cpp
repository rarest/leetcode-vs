/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
        rotate90(matrix);
    }

    void rotate90(vector<vector<int>>& matrix) {
        fliptlrb(matrix);
        fliplr(matrix);
    }

    void rotate270(vector<vector<int>>& matrix) {
        fliptlrb(matrix);
        fliptb(matrix);
    }

    void fliptlrb(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i < n- 1; i++) {
            for(int j = i + 1; j < n; j ++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void fliplr(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mid = n >> 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j< mid; j++) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }

    void fliptb(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mid = n >> 1;
        for(int i = 0; i < mid; i++) {
            for(int j = 0; j< n; j++) {
                swap(matrix[i][j] ,matrix[n-1-i][j]);
            }
        }
    }
};
// @lc code=end

