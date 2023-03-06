




// Surprising, AC after first writing.
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        int res = 0, end = 0, farPos = 0;
        
        while (end < time) {
            for (int j = 0; j < clips.size(); ++j) {
                if (clips[j][0] <= end) {
                    farPos = max(farPos, clips[j][1]);
                }
            }
            if (farPos == end) return -1;
            end = farPos;
            res++;
        }
        return res
    }
};


// I tried several times to ensure there is no bug.
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {        
        sort(clips.begin(), clips.end());
        int res = 0, end = 0, farPos = 0;
        for (int i = 0; i < clips.size() && end < time; res++) {
            for (; i < clips.size() && clips[i][0] <= end; ++i) {
                if (clips[i][1] > farPos) {
                    farPos = clips[i][1];
                }
            }
            if (farPos == end) return -1;
            end = farPos;
        }
        if (end < time) return -1;
        return res;
    }
};


