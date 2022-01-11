/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> buckets;
    int maxCount = 0;
    for (const int &val: nums) {
        maxCount = std::max(maxCount, ++buckets[val]);
    }
    vector<vector<int> > frequentArray(buckets.size() + 1);
    for (const auto &bucket: buckets) {
        frequentArray[bucket.second].push_back(bucket.first);
    }
    int j = 0;
    std::vector<int> ret;
    for (size_t i = frequentArray.size() - 1; i >= 0 && j < k; i--) {
        for (const int &val: frequentArray[i]) {
            if (j < k) {
                ret.push_back(val);
                ++j;
            } else
                break;
        }
    }
    return ret;
    }


};
// @lc code=end

