#include "../common.h"

/**
 * @brief Given an array of prices, you can trade the stocks with buying and selling.
 * At one time, you can only hold at most one stock.
 * You may complete at most two transactions.
 * 
 * 
 * 
 */


class Solution1 {
public:
    int maxProfit(vector<int> &prices) {
        int ans = solve(prices, 0, 4); // starting with day 0 and max 4 transactions can be done
        return ans;
    }

    int solve(vector<int> &prices, int day, int transactionsLeft) {
        if (day == prices.size()) return 0;
        if (transactionsLeft == 0) return 0;

        // choice 1
        // no transaction today
        int ans1 = solve(prices, day + 1, transactionsLeft);

        // choice 2
        // doing the possible transaction today
        int ans2 = 0;
        bool buy = (transactionsLeft % 2 == 0);
        if (buy == true) { // buy
            ans2 = -prices[day] + solve(prices, day + 1, transactionsLeft - 1);
        } else { // sell
            ans2 = prices[day] + solve(prices, day + 1, transactionsLeft - 1);
        }

        return max(ans1, ans2);
    }
};

class Solution2 {
public:
    int solve(vector<int> &prices, int day, int transactionsLeft, vector<vector<int>> &memo) {
        if (day == prices.size()) return 0;
        if (transactionsLeft == 0) return 0;

        int &ans = memo[day][transactionsLeft];
        if (ans != -1) return ans;

        // choice 1, no transaction today
        int ans1 = solve(prices, day + 1, transactionsLeft, memo);

        // choice 2, doing the possible transaction today
        int ans2 = 0;
        bool buy = (transactionsLeft % 2 == 0);
        
        if (buy == true) {
            ans2 = -prices[day] + solve(prices, day + 1, transactionsLeft - 1, memo);
        } else {
            ans2 = prices[day] + solve(prices, day + 1, transactionsLeft - 1, memo);
        }
        
        return ans = max(ans1, ans2); // ans is a reference
    }

    int maxProfit(vector<int> &prices) {
        vector<vector<int>> memo(prices.size(), vector<int>(5,-1));
        int ans = solve(prices, 0, 4, memo);
        return ans;
    }

};

class Solution3 {
public:
    int maxProfit(vector<int> &prices) {
        int dp[prices.size() + 1][5];

        for (int day = (int) prices.size(); day >= 0; --day) {
            for (int transactionsLeft = 0; transactionsLeft <= 4; ++transactionsLeft) {
                int &ans = dp[day][transactionsLeft];
                if (day == prices.size()) ans = 0;
                else if (transactionsLeft == 0) ans = 0;
                else {
                    // choice 1, no transaction today
                    int ans1 = dp[day + 1][transactionsLeft];

                    // choice 2, doing the possible transaction today
                    int ans2 = 0;
                    bool buy = (transactionsLeft % 2 == 0);
                    if (buy == true) { // buy
                        ans2 = -prices[day] + dp[day + 1][transactionsLeft - 1];
                    } else { // sell
                        ans2 = prices[day] + dp[day + 1][transactionsLeft - 1];
                    }

                    ans = max(ans1, ans2);
                }
            }
        }
        return dp[0][4];
    }
};

class Solution4 {
public:
    int maxProfit(vector<int> &prices) {
        int dp[2][5];
        for (int day = (int)prices.size(); day >= 0; --day) {
            for (int transactionsLeft = 0; transactionsLeft <= 4; ++transactionsLeft) {
                int &ans = dp[day][transactionsLeft];
                if (day == prices.size()) ans = 0;
                else if (transactionsLeft == 0) ans = 0;
                else {
                    // choice 1, no transaction today
                    int ans1 = dp[(day+1) % 2][transactionsLeft];

                    // choice 2, doing the possible transaction today
                    int ans2 = 0;
                    bool buy = (transactionsLeft % 2 == 0);

                    if (buy == true) { // buy
                        ans2 = -prices[day] + dp[(day + 1) % 2][transactionsLeft - 1];
                    } else { // sell
                        ans2 = prices[day] + dp[(day + 1) % 2][transactionsLeft - 1];
                    }
                    ans = max(ans1, ans2);
                }
            }
        }
        return dp[0][4];
    }

};

class Jiuzhang {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int K = 2;
        // corner case
        if (n == 0) return 0;
        // main part
        vector<vector<int>> dp(K + 1, vector<int>(n));
        for (int i = 1; i < K + 1; ++i) {
            int maxDiff = -prices[0]; // Important
            for (int j = 1; j < n; ++j) {
                maxDiff = max(maxDiff, dp[i-1][j-1] - prices[j]); // Important
                dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff);
            }
        }
    }
};




class Leetcode {
public:
    int maxProfit(vector<int> &prices) {
        int t1Cost = INT_MAX, t2Cost = INT_MAX;
        int t1Profit = 0, t2Profit = 0;

        for (int price : prices) {
            // the maximum profit if only one transaction is allowed
            t1Cost = min(t1Cost, price);
            t1Profit = max(t1Profit, price - t1Cost);
            // re-invest the gained profit in the second transaction
            t2Cost = min(t2Cost, price - t1Profit);
            t2Profit = max(t2Profit, price - t2Cost);
        }
        return t2Profit;
    }
};





