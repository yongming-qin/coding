#include "../common.h"

/**
 * @brief Can buy many times. Only hold on stock at one time.
 * 
 * 
 * 
 */


// Solution. O(n)



class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.length - 1) {
            while (i < prices.length - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.length - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
}






// DP solution. O(n^2)
class Mine {
public:
    int maxProfit(vector<int>& prices) {

        // dp[i] selling on day i. The maximum profit till day i.
        // dp[0] and others are initialized to 0.
        vector<int> dp(prices.size(), 0);
        for (int i = 1; i < prices.size(); ++i) {
            // the previous selling day. search the next buying
            for (int j = 0; j < i; ++j) {
                int profit = prices[j] < prices[i] ?
                    dp[j] + prices[i] - prices[j] : dp[j];
                dp[i] = max(dp[i], profit);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

