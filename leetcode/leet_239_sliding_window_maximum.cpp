
#include "../common.h"

/**
 * @brief 
 * 
 * 
 * 
 */


// priority queue. O(nlgn)
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        priority_queue<pair<int,int>> pq; // max heap
        int cnt = 0;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
            if (i >= k - 1) ans.push_back(pq.top().first);
            while (pq.size() && i - pq.top().second + 1 >= k) pq.pop();
        }
        return ans;
    }
};

class Solution2 {
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> ans;
        deque<int> dq; // index
        // 
        for (int i = 0; i < nums.size(); ++i) {
            if (dq.size() && i - dq.front() + 1 >= k) dq.pop_front();

            while (dq.size() && nums[i] >= nums[dq.back()]) dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1) ans.push_back(nums[dq.back()]);

        }

        return ans;
    }
};