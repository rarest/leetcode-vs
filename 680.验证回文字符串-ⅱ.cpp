/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i<j)
        {
            if(s[i] != s[j])
                return checkPalindrome(s, i+1, j)||checkPalindrome(s,i, j-1);
            else {
                ++i;
                --j;
            }
            
        }
       return true;         

    }
    bool checkPalindrome(string s, int i, int j) {
        while (i<j)
        {
           if(s[i++] != s[j--])
            return false;
            
        }
        return true;        
    }
};
// @lc code=end

