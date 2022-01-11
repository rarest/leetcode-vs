/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int p = 0, q = 1;

        while (q < n)
        {
           if(nums[p] != nums[q])
            nums[++p] = nums[q];
           ++q;        
        }
        return p+1;
        
    }
};
// @lc code=end

