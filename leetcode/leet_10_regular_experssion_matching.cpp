#include "../common.h"
/**
 * @brief 
 * 
 * 
 */


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && )
                } else {
                    dp[i][j] = i && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[m][n];

    }



}

class Mine1 {
public:
    bool isMatch(string s, string p) {
        return dfs(s, 0, p, 0);
    }

    bool dfs(string& s, int is, string& p, int ip) {
        if (is == s.size() && ip == p.size()) return true;
        else if (ip == p.size()) return false;

        // check two chars
        if (ip == p.size() - 1) {
            return (s[is] == p[ip] || p[ip] == '.') && dfs(s, is+1, p, ip+1);
        }
        // else
        if (p[ip+1] == '*') {
            if (p[ip] == '.') { // ".*"
                for (int i = is; i <= s.size(); ++i) {
                    if (dfs(s, i, p, ip+2)) return true;
                }
                return false;
            } else {            // "a*"
                for (int i = is; i <= s.size(); ++i) {
                    if (dfs(s, i, p, ip+2)) return true;
                    if (i == s.size() || s[i] != p[ip]) break;
                }
                return false;
            }
        } else {
            return (s[is] == p[ip] || p[ip] == '.') && dfs(s, is+1, p, ip+1);
        }
    }



};



int main() {
    Solution sol;
    string s = "bbabcaccacbcacaa";
    string p = ".*.c*a*.c";
    cout << sol.isMatch(s, p) << endl;

    cout << "end of the running" << endl;

    return 0;
}
