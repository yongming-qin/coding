



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX; // the diff
        int ans; // the sum
        for (int i = 0; i < nums.size() - 2; ++i) {
            auto [j, k] = twoClosest(nums, i + 1, target - nums[i]);
            int curDiff = abs(nums[i] + nums[j] + nums[k] - target);
            if (curDiff < diff) {
                diff = curDiff;
                ans = nums[i] + nums[j] + nums[k];
            }
        }
        return ans;
    }
    
    
    pair<int,int> twoClosest(vector<int> &nums, int start, int target) {
        int end = nums.size() - 1;
        int diff = INT_MAX;
        pair<int,int> ans = {start, end};
        
        while (start < end) {
            int s = nums[start] + nums[end];
            int curDiff = abs(s - target);
            if ( curDiff < diff) {
                diff = curDiff;
                ans = {start, end};
            }
            if (s > target) --end;
            else if (s < target) ++start;
            else return {start,end};
        }
        return ans;
    }
};