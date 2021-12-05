/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void backTracing(vector<vector<int>> &ans, vector<int>&comb, int &count, int pos, int n, int k){
        if(count == k){
            ans.push_back(comb);
            return;
        }
        for(int i = pos; i <= n; i++){
            comb[count++] = i;
            backTracing(ans, comb, count, i + 1, n, k);
            --count;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k, 0);
        int count = 0;
        backTracing(ans, comb, count, 1, n, k);
        return ans;
    }
};
// @lc code=end

