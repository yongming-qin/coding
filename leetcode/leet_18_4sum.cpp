#include "../common.h"



class Mine {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // Important
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int targetForTwo = target - nums[i] - nums[j];
                if (nums[j + 1] > targetForTwo / 2) break;
                twoSum(nums, j + 1, targetForTwo, {nums[i],nums[j]}, ans);
            }
        }
        return ans;
    }
    
    
    void twoSum(vector<int> &nums, int start, int target,
                vector<int> indices, vector<vector<int>> &ans)
    {
        int end = nums.size() - 1;
        while (start < end) { // SELF different from binary search
            int s = nums[start] + nums[end];
            if (s < target) {++start;}
            else if (s > target) {--end;}
            else {
                indices.push_back(nums[start]);
                indices.push_back(nums[end]);
                // for (auto val : indices) cout << val << " ";
                // cout << endl;
                bool repeated = true;
                if (ans.size()) {
                    for (int k = 0; k < 4; ++k) {
                        if (indices[k] != ans.back()[k]) {
                            repeated = false;
                            break;
                        }
                    }
                }
                if (ans.empty() || !repeated) ans.push_back(indices); // Question
                indices.pop_back(); indices.pop_back();
                ++start; --end; // Important
            }
        }
    }
};


class MineModified {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // Important
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                long long targetForTwo = (long long)target - nums[i] - nums[j];
                if (nums[j + 1] > targetForTwo / 2) break;
                twoSum(nums, j + 1, targetForTwo, {nums[i],nums[j]}, ans);
            }
        }
        return ans;
    }
    
    
    void twoSum(vector<int> &nums, int firstIdx, long target,
                vector<int> indices, vector<vector<int>> &ans)
    {
        int start = firstIdx, end = nums.size() - 1;
        while (start < end) { // SELF different from binary search
            long long s = nums[start] + nums[end];
            // cout << start << " " << end << endl;
            if (s < target || (start > firstIdx && nums[start] == nums[start-1])) {
                ++start;
            }
            else if (s > target || (end < nums.size() -1 && nums[end] == nums[end+1])) {
                --end;
            }
            else {
                indices.push_back(nums[start]);
                indices.push_back(nums[end]);
                ans.push_back(indices); // Question
                indices.pop_back(); indices.pop_back();
                ++start; --end; // Important
            }
        }
    }
};




class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int> &nums, long long target, int start, int k)
    {
        vector<vector<int>> res;

        // If we have run out of numbers to add, return res.
        if (start == nums.size())
        {
            return res;
        }

        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        long long average_value = target / k;

        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if (nums[start] > average_value || average_value > nums.back())
        {
            return res;
        }

        if (k == 2)
        {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i)
        {
            if (i == start || nums[i - 1] != nums[i])
            {
                for (vector<int> &subset : kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1))
                {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }

        return res;
    }

    vector<vector<int>> twoSum(vector<int> &nums, long long target, int start)
    {
        vector<vector<int>> res;
        int lo = start, hi = int(nums.size()) - 1;

        while (lo < hi)
        {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1]))
            {
                ++lo;
            }
            else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
            {
                --hi;
            }
            else
            {
                res.push_back({nums[lo++], nums[hi--]});
            }
        }

        return res;
    }
};