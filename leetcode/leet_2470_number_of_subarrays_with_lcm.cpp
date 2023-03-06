#include "../common.h"


/**
 * @brief Given an array of integers, find the number of subarrays of which the least common multiple is k.
 * 
 * 
 */


// O(n d(k))
int subarrayLCM(vector<int> &nums, int k) {
    int res = 0;
    unordered_map<int, int> m; // amount
    for (int i = 0, j = 0; i < nums.size(); ++i) {
        ++m[nums[i]];
        unordered_map<int,int> m1;
        for (auto [d, cnt] : m) {
            // just calculate the lcm of two integers
            // This is a formula.
            int lcm = d * nums[i] / gcd(d, nums[i]);
            if (lcm == k) res += cnt;
            if (k % lcm == 0) m1[lcm] += cnt;
        }// ?? NOT understand
        swap(m, m1);
    }
    return res;



}