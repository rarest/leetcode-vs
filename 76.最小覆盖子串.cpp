/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        //统计
        int nums[128] = {};
        bool flag[128] = {};
        for(char c:t) {
            ++nums[c];
            flag[c] = true;
        }
        int cnt = 0; int l = 0; int min_l =0; int min_size = s.size() + 1;
        for(int r = 0; r < s.size(); ++r) {
            if(flag[s[r]]){
                if(--nums[s[r]]>=0){
                    ++cnt;
                }
                while (cnt == t.size())
                {
                    if(r-l+1 < min_size) {
                        min_l = l;
                        min_size = r-l+1;
                    }
                    if(flag[s[l]] && ++ nums[s[l]]>0){
                        --cnt;
                    }
                    ++l;
                }
                
            }

        }        
        return min_size > s.size()?"":s.substr(min_l, min_size);
    }
};
// @lc code=end

