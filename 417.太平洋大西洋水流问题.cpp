/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<int>>&heights, int r, int c, vector<vector<bool>> &canReached) {
        if(canReached[r][c])
            return;
        canReached[r][c] = true;
        int axis[5] = {0, 1, 0, -1, 0};
        for(int i = 0; i < 4; ++i) {
            int r1 = r + axis[i];
            int c1 = c + axis[i + 1];
            if(r1 >= 0 && c1 >= 0 && r1 < heights.size() && c1 < heights[0].size() && heights[r1][c1] >= heights[r][c])
                dfs(heights, r1, c1, canReached);

        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> canReachedP(m, vector<bool>(n, false));
        vector<vector<bool>> canReachedA(m, vector<bool>(n, false));
        for(int i = 0; i<m; ++i ) {
            dfs(heights, i, 0, canReachedP);
            dfs(heights, i, n - 1, canReachedA);
        }
        for(int i = 0; i<n; ++i) {
            dfs(heights, 0, i, canReachedP);
            dfs(heights, m - 1, i, canReachedA);
        }
        vector<vector<int>> ret;
        for(int i = 0; i< m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(canReachedP[i][j] && canReachedA[i][j]) {
                    ret.push_back({i, j});
                }
            }
        }
        return ret;
    }
};
// @lc code=end

