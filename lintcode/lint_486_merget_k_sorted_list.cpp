
#include "common.h"

/**
 * @brief Given k sorted integer arrays, merge them into one sorted array.
 * 
 */


// Yongming
class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here
        using T = tuple<int,int,int>;
        auto comp = [](T &a, T &b) {return get<0>(a) > get<0>(b);};
        priority_queue<T, vector<T>, decltype(comp)> pq(comp); // element, which array, idx of this array
        int n = arrays.size();
        for (int i = 0; i < n; ++i) {
            if (arrays[i].size()) {
                pq.push({arrays[i][0], i, 0});
            }
        }

        vector<int> ans;
        while (pq.size()) {
            auto cur = pq.top(); pq.pop();
            int ele = get<0>(cur);
            int whichArray = get<1>(cur);
            int idx = get<2>(cur);
            ans.push_back(ele);
            if (idx + 1 < arrays[whichArray].size()) {
                pq.push({arrays[whichArray][idx + 1], whichArray, idx + 1});
            }
        }
        return ans;
    }
};


// Linghu
struct Node {
    int row, col, val;
    Node(int r, int c, int v) : row(r), col(c), val(v) {};
    bool operator < (const Node &obj) const {
        return val > obj.val;
    }
};

class Solution {
public:
    vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {


        priority_queue<Node> pq;


        pq.push(Node(1,2,3)); // use case
    }
};