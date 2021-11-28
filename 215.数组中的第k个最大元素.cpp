/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:

    int partation(vector<int> & data, int l, int r){
        int idx = rand()%(r-l+1)+l;
        swap(data[l], data[idx]);
        int key = data[l];
        int pos = l;
        for(int i = l+1; i <=r; ++i){
            if(data[i] >= key){
                swap(data[i], data[++pos]);
            }
        }
        swap(data[l],data[pos]);
        return pos;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        int l = 0; int r = nums.size() - 1;
        while (l < r)
        {        
            int pos = partation(nums, l, r);
            if(pos == k-1)
                return nums[pos];
            if(pos > k-1)
                r = pos-1;
            else
                l = pos+1;
        }
        return nums[r];        
    }
};
// @lc code=end

