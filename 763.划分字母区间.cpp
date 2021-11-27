/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.empty())
            return vector<int>{0};
        int array[26];
        for(int i = 0; i< s.size(); ++i){
            array[s[i]-'a'] = i;
        }
        int end = 0;
        int start = 0;
        vector<int> ret;
        for(int i = 0; i< s.size(); ++i){
            end = std::max(end, array[s[i] - 'a']);
            if(end == i) {
                ret.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ret;
    }
};
// @lc code=end

