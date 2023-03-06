#include "common.h"

/**
 * @brief Given a non-empty binary search tree and a target value, find k values in the bst
 * that are closest to the target.
 * 
 */

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     *          we will sort your return value in output
     */
    vector<int> closestKValues(TreeNode *root, double target, int k) {
        // write your code here
        stack<TreeNode*> suc;
        stack<TreeNode*> pre;
        initialize(root, target, suc, pre);
        // initialize iterator
        TreeNode* left = getPredecessor(pre);
        TreeNode* right = getSuccessor(suc);
        // idea: merge two sorted array
        vector<int> ans;
        while (k--) {
            if (isLeftCloser(target, left, right)) {
                ans.push_back(left->val);
                left = getPredecessor(pre);
            } else {
                ans.push_back(right->val);
                right = getSuccessor(suc);
            }
        }
        return ans;
    }

    bool isLeftCloser(double target, TreeNode* left, TreeNode* right) {
        if (!right) return true;
        if (!left) return false;
        return fabs(left->val - target) < fabs(right->val - target);
    }


    void initialize(TreeNode* root, double target,
                    stack<TreeNode*> &suc, stack<TreeNode*> &pre) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->val > target) {
                suc.push(cur);
                cur = cur->left;
            } else {
                pre.push(cur);
                cur = cur->right;
            }
        }
    }

    TreeNode* getSuccessor(stack<TreeNode*> &suc) {
        if (suc.empty()) return nullptr;
        TreeNode* node = suc.top(); suc.pop();
        TreeNode* cur = node->right;
        while (cur) {
            suc.push(cur); cur = cur->left;
        }
        return node;
    }

    TreeNode* getPredecessor(stack<TreeNode*> &pre) {
        if (pre.empty()) return nullptr;
        TreeNode* node = pre.top(); pre.pop();
        TreeNode* cur = node->left;
        while (cur) {
            pre.push(cur); cur = cur->right;
        }
        return node;
    }


};

