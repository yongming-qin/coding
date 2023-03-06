
#include "common.h"

/**
 * @brief Given a k-ary tree, find the length of the longest consecutive sequence path.
 * The path could be start and end at any node in the tree.
 * 
 */


/**
 * Definition for a multi tree node.
 * struct MultiTreeNode {
 *     int val;
 *     vector<MultiTreeNode*> children;
 *     MultiTreeNode(int x) : val(x) {}
 * };
 */

struct Result {
    int len; // length of longest, include root
    int inc, dec; // for child, consecutive sequnce; exclude root
    Result(int len, int inc, int dec) {
        this->len = len; this->inc = inc; this->dec = dec;
    }
};

class Solution {
public:
    /**
     * @param root the root of k-ary tree
     * @return the length of the longest consecutive sequence path
     */
    int longestConsecutive3(MultiTreeNode* root) {
        // Write your code here
        return divide(root).len; 
    }

    Result divide(MultiTreeNode* root) {
        if (root == nullptr) return Result(0,0,0);
        int len = 0, inc = 0, dec = 0;
        for (auto child : root->children) {
            Result res = divide(child);
            if (child->val + 1 == root->val) inc = max(inc, res.inc + 1);
            if (child->val - 1 == root->val) dec = max(dec, res.dec + 1);
            len = max(len, res.len);
        }
        len = max(len, inc + dec + 1);
        return Result(len, inc, dec);
    }


};
