#include "../common.h"
/**
 * @brief 
 * 
 * 
 * 
 * 
 */

class Mine {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int divisor = nums[i];
            if (divisor == k) {++ans;}
            
            for (int j = i + 1; j < nums.size(); ++j) {
                divisor = gcd(divisor, nums[j]);
                if (divisor == k) {++ans; continue;}
                else if (divisor < k) {break;}
            }
            
        }
        return ans;
    }
};

// Brutal Force O(n^2)
int subarrayGCD(vector<int>& nums, int k) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i)
        for (int j = i; j < nums.size() && nums[j] % k == 0; ++j) {
            nums[i] = gcd(nums[i], nums[j]);
            res += nums[i] == k;
        }
    return res;
}


// Count GCDs O(n log m)
int subarrayGCD(vector<int>& nums, int k) {
    int res = 0;
    unordered_map<int, int> gcds;
    for (int i = 0; i < nums.size(); ++i) {
        unordered_map<int, int> gcds1;
        if (nums[i] % k == 0) {
            ++gcds[nums[i]];
            for (auto [prev_gcd, cnt] : gcds)
                gcds1[gcd(prev_gcd, nums[i])] += cnt;
        }
        res += gcds1[k];
        swap(gcds, gcds1);
    }
    return res;
}