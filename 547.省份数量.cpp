/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool> &visited, int idx) {
        visited[idx] = true;
        for(int j = 0; j < isConnected[idx].size(); ++j) {
            if(!visited[j] && isConnected[idx][j]) {
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<bool> visited(isConnected.size(), false);
        for(int i = 0; i < isConnected.size(); ++i) {
            if(!visited[i]){
                dfs(isConnected, visited, i);
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end

