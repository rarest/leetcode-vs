/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        { 
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[r] == nums[mid]){
                --r;
            } else if(nums[mid] < nums[r]) {// 右边有序
                if(nums[mid] < target && target <= nums[r]){
                    l = mid + 1;
                } else {
                    r = mid;
                }

            }else {//左边有序
                if(nums[l] <= target && target < nums[mid]){
                    r = mid;
                }else {
                    l = mid + 1;
                }
            }
        }
        return nums[r] == target; 
    }
};
// @lc code=end

