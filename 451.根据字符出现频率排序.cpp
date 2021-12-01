/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<char, int> bucket;
        int maxCount = 0;
        for(const char& c:s){
            maxCount = std::max(maxCount, ++bucket[c]);
        }
        vector<string> vectors(maxCount+1);
        for(const auto & [ch, num]: bucket){
            vectors[num].push_back(ch);
        }
        string ret;
        for(int i = maxCount; i >0; --i){
            string  str = vectors[i];
            for(const auto &ch: str){
                for(int k = 0; k< i; ++k)
                    ret.push_back(ch);
            }
        }
        return ret;

    }
};
// @lc code=end

