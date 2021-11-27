/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        std::sort(points.begin(),points.end(),[](const vector<int>& v1,const vector<int>&v2){
            return v1[1] < v2[1];
        });
        int pos = points[0][1];
        int arrowCount = 1;
        for(int i = 0; i < points.size(); ++i){
            if(points[i][0] > pos) {
                pos = points[i][1];
                ++arrowCount;
            }
        }
        return arrowCount;
    }
};
// @lc code=end

