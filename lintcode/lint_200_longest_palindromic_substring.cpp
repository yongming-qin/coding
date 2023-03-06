#include "common.h"


/**
 * @brief 
 * Given a string S, find the longest palindromic substring in S.
 * You may assume that the longest ...
 * 
 */


// Yongming
class Solution {
public:
    /**
     * @param s: input string
     * @return: a string as the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        int num = 0, start = 0, end = 0;
        // odd number
        for (int i = 0; i < s.size(); ++i) {
            auto seg = segPalin(s, i, i);
            int numSeg = seg.second - seg.first + 1;
            if (numSeg > num) {
                start = seg.first; end = seg.second;
                num = numSeg;
            }
        }
        // even number
        for (int i = 0; i < s.size() - 1; ++i) {
            auto seg = segPalin(s, i, i+1);
            int numSeg = seg.second - seg.first + 1;
            if (numSeg > num) {
                start = seg.first; end = seg.second;
                num = numSeg;
            }
        }
        string ans;
        for (int i = start; i <= end; ++i) {
            ans = ans + s[i];
        }
        return ans;
    }

    // from center to outside. check palindrome
    pair<int,int> segPalin(string &s, int start, int end) {
        while (start >= 0 && end < s.size()) {
            if (s[start] != s[end]) break;
            start--; end++;
        }
        return {start + 1, end - 1}; //Key
    }
};