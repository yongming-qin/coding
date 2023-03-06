#include "../common.h"

/**
 * @brief Given a sequence of numbers, find the triplets of three numbers which the sum of the three can only be divided by one of the three.
 * Return the number of all triplets. The sequence and indices of the numbers matter.
 * 
 */



class Mine {
public:
    long long singleDivisorTriplet(vector<int>& nums) {
        vector<int> times(101, 0);
        for (int nu : nums) {
            times[nu]++;
        }
        
        long long ans;
        vector<int> seq;
        dfs(times, 0, seq, ans);
        return ans * 6;
    }
    
    
    void dfs(vector<int> &times, int idx, vector<int> &seq, long long &ans) {
        if (seq.size() == 3) {
            int s = reduce(seq.begin(), seq.end());
            int nDiv = 0;
            for (int k = 0; k < 3; ++k) {
                if (s % seq[k] == 0) ++nDiv;
            }
            if (nDiv == 1) {
                if (seq[0] == seq[1]) ans += (long long)times[seq[0]] * (times[seq[0]] - 1) / 2 * times[seq[2]];
                else if (seq[1] == seq[2]) {
                    ans += (long long)times[seq[2]] * (times[seq[2]] - 1) / 2 * times[seq[0]];
                }
                else ans += (long long)times[seq[0]] * times[seq[1]] * times[seq[2]];
            }
            return;
        }
        if (idx >= times.size()) return;
                 
        for (int i = idx; i < times.size(); ++i) {
            if (times[i] == 0) continue;
            seq.push_back(i);
            dfs(times, i + 1, seq, ans);
            // two same values
            if (times[i] >= 2 && seq.size() < 3) {
                seq.push_back(i);
                dfs(times, i + 1, seq, ans);
                seq.pop_back();
            }
            seq.pop_back();
        }

    }
    

};


long long singleDivisorTriplet(vector<int> &nums) {
    long long res = 0, cnt[101] = {};
    for (int n : nums) ++cnt[n];
    for (int i = 1; i <= 100; ++i) {
        for (int j = i; cnt[i] && j <= 100; ++j) {
            for (int k = j + (i == j); cnt[j] && k <= 100; ++k) {
                int s = i + j + k;
                if (cnt[k] && (!(s%i) + !(s%j) + !(s%k) == 1)) {
                    if (i == j) res += cnt[i] * (cnt[i] - 1) / 2 * cnt[k];
                    else if (j == k) res += cnt[i] * cnt[j] * (cnt[j] - 1) / 2;
                    else res += cnt[i] * cnt[j] * cnt[k];
                }
            }
        }
    }
    return res * 6;
}


