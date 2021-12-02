/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland_1(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                int area = 0;
                std::stack<int> nodeStack;
                nodeStack.push(j);
                nodeStack.push(i);
                int xs[4] = {1, -1, 0, 0};
                int ys[4] = {0, 0, 1, -1};
                while(!nodeStack.empty()) {
                    int x = nodeStack.top();
                    nodeStack.pop();
                    int y = nodeStack.top();
                    nodeStack.pop();
                    if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]==0)
                        continue;
                    ++area;
                    grid[x][y] = 0;
                    for(int k = 0; k<4; ++k) {
                        nodeStack.push(y + ys[k]);
                        nodeStack.push(x + xs[k]);
                    }
                }
                maxArea = std::max(maxArea, area);
            }
        }
        return maxArea;
    }


    int maxAreaOfIsland_dfs(vector<vector<int>>& grid, int i, int j) {
        if(i<0|| j<0 || i >= grid.size() || j>= grid[0].size()||grid[i][j] == 0)
            return 0;
        int xs[4] = {0, 0, 1, -1};
        int ys[4] = {1, -1, 0, 0};
        grid[i][j] = 0;
        int area = 1;
        for(int k = 0; k < 4; k++) {
            area += maxAreaOfIsland_dfs(grid, i+xs[k], j +ys[k]);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                maxArea = std::max(maxArea, maxAreaOfIsland_dfs(grid, i,j));
            }
        }
        return maxArea;
    }

};
// @lc code=end

