#include "../common.h"


/**
 * @brief 
 * 
 * 
 * 
 */



class Solution {
public:

    int minTaps(int n, vector<int> &ranges) {
        vector<vector<int>> segs;
        for (int i = 0; i < ranges.size(); ++i) {
            segs.push_back({max(0,i-ranges[i]), i+ranges[i]});
        }
        sort(segs.begin(), segs.end());

        int preEnd = 0, farReach = 0, res = 0;

        for (int i = 0; i < segs.size() && farReach < n; res++) {
            for (; i < segs.size() && segs[i][0] <= preEnd; ++i) {
                farReach = max(farReach, segs[i][1]);
            }
            if (farReach == preEnd) return -1;
            preEnd = farReach;
        }
        return res;
    }

};

class Mine {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<pair<int,int>> segs;
        for (int i = 0; i < ranges.size(); ++i) {
            segs.push_back({i-ranges[i], i+ranges[i]});
        }
        sort(segs.begin(), segs.end(),
             [](pair<int,int> seg1, pair<int,int> seg2) {
                 return seg1.first < seg2.first;
             }
            );
        
        int start = 0, end = 0, nTaps = 0;
        bool canConnect = false;
        for (int i = 0; i < ranges.size(); ) {
            if (segs[i].first <= start) {
                canConnect = true;
                end = max(end, segs[i].second);
                ++i;
            } else {
                if (!canConnect) return -1;
                ++nTaps;
                if (end >= n) return nTaps;
                canConnect = false;
                start = end; // Then go to the if ()
            }
        }
        return nTaps + 1;
    }
};