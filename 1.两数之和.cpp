/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    vector<int> array = {1,7,3,6};
    Solution solution;
    auto ret = solution.twoSum(array, 10);
    for (int i = 0; i < ret.size(); i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
    return 0;
}

// @lc code=end