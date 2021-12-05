/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    void backTracking(vector<int> & nums, vector<vector<int>> & ans, int index) {
        if(index == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); ++i){
            swap(nums[index], nums[i]);
            backTracking(nums, ans, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backTracking(nums, ans, 0);
        return ans;
    }
};
// @lc code=end

