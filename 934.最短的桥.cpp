/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        std::queue<std::pair<int,int>>points;
        bool completed = false;
        for(int i = 0; i < m; ++i) {
            if(completed)
                break;
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    dfs(grid, points, m, n, i, j);
                    completed = true;
                    break;
                }
            }
        }
        int level = 0;
        int x, y;
        int offsets[] = {-1, 0, 1, 0, -1};
        while (!points.empty())
        {
            level++;
            int points_num = points.size(); 
            while (points_num--)
            {
                auto[r,c] = points.front();
                points.pop();
                for(int i = 0; i < 4; ++i){
                    x = r + offsets[i], y = c + offsets[i + 1];
                    if(x < 0 || y < 0 || x == m || y == n || grid[x][y] == 2) {
                        continue;
                    }            
                    if(grid[x][y] == 1) {
                        return level;
                    }
                    points.push({x,y});
                    grid[x][y] = 2;
                }
            }           
           
        }
        
        return 0;

    }
    void dfs(vector<vector<int>>& grid, std::queue<std::pair<int,int>>& points, int m, int n, int x, int y){
        if(x < 0 || x == m || y < 0 || y == n || grid[x][y] == 2) {
            return;
        }
        if(grid[x][y] == 0) {
            points.push({x, y});
            return;
        }
        grid[x][y] = 2;
        int offset[5]= {-1, 0, 1, 0, -1};
        for(int i = 0; i <4; ++i) {
            int x1 = x + offset[i], y1 = y + offset[i+1];
            dfs(grid, points, m, n, x1, y1);
        }

    }
};
// @lc code=end

