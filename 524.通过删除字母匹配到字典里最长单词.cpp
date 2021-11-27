/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b){
            if(a.size() == b.size()) 
                return a<b;
            else 
                return a.size() > b.size();
        });

        for(const string & str : dictionary) {
            int i = 0, j = 0;
            while (i < s.size() && j < str.size())
            {
                if(s[i] == str[j])
                    ++j;
                ++i;
            }
            if(j == str.size()) 
                return str;
        }
        return "";
    }
};
// @lc code=end

