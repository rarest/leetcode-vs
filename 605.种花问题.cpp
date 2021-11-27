/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int count = 0;
        for(int i = 0; i < size; ++i ) {            
            if(flowerbed[i] == 0 
            && (i==0 || flowerbed[i-1] == 0) 
            && ((i + 1) == size||flowerbed[i+1]==0)) {
                flowerbed[i] = 1;
                ++count;
                
            }
        }
        return n<=count;
    }
};
// @lc code=end

