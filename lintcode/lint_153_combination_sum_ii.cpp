#include "common.h"


/**
 * @brief Given an array nums and a target value, find all combinations of
 * values in nums where the numbers sum to the target.
 * 
 */

// Yongming
class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     *          we will sort your return value in output
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<int> nums(num);
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> comb;
        dfs(nums, target, 0, comb, ans);
        return ans;
    }

    void dfs(vector<int> &nums, int target, int idx,
        vector<int> &comb, vector<vector<int>> &ans)
    {
        if (idx == nums.size()) return;

        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1]) continue; // avoid duplications
            int newTarget = target - nums[i];
            if (newTarget == 0) {
                comb.push_back(nums[i]);
                ans.push_back(comb); // default new one?
                comb.pop_back();
                continue;
            }
            if (newTarget < nums[i]) continue; // pruning
            comb.push_back(nums[i]);
            dfs(nums, newTarget, i + 1, comb, ans);
            comb.pop_back();
        }
    }
};