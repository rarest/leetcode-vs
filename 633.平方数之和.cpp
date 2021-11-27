/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long l = 0, r = (int)sqrt(c);
        while (l <= r)
        {
            long sum = l*l + r*r;
            if(sum == c)
                return true;
            else if(sum > c)
                --r;
            else 
                ++l;
        }
        return false;        
    }
};
// @lc code=end

