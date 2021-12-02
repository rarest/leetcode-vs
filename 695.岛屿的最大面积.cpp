/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
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
};
// @lc code=end

