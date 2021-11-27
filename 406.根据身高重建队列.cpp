/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        std::sort(people.begin(), people.end(),[](const vector<int> & v1, const vector<int>& v2){
            return v1[0]<v2[0]||(v1[0]==v2[0]&& v1[1]>v2[1]);
        });
        int n = people.size(); 
        vector<vector<int>> ret(n);
        for(const vector<int> &v : people) {
            int spaces = v[1] + 1;
            for(int i = 0; i < n; i++){
                if(ret[i].empty()){
                    --spaces;
                    if(!spaces) {
                        ret[i] = v;
                        break;
                    }
                }
            }            
        }
        return ret;
    }
};
// @lc code=end

