#include "common.h"

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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode *root, int value) {
        // write your code here
        if (root == nullptr) return nullptr;
        TreeNode *fake; fake->left = root; // will new fake be destroyed
        TreeNode *cur = root;
        TreeNode *parent = fake;

        // find the node
        while (cur) {
            if (value == cur->val) break;
            parent = cur;
            if (value < cur->val) {cur = cur->left;}
            else if (value > cur->val) {cur = cur->right;}
        }
        if (cur == nullptr) return fake->left; // not found

        // cur node is leaf node
        if (cur->left == nullptr && cur->right == nullptr) {
            // change parent
            if (parent->left == cur) {parent->left = nullptr;}
            else {parent->right = nullptr;}
        }
        // cur node only has left child
        else if (cur->right == nullptr) {
            if (parent->left == cur) {parent->left = cur->left;}
            else {parent->right = cur->left;}
        }
        // cur node only has right child
        else if (cur->left == nullptr) {
            if (parent->left == cur) {parent->left = cur->right;}
            else {parent->right = cur->right;}
        }
        // node has both left and right child
        // else cases. separate namespace
        else {
            if (cur->right->left == nullptr) {
                if (parent->left == cur) {parent->left = cur->right;}
                else {parent->right = cur->right;}
                cur->right->left = cur->left;
            } else {
                TreeNode* tmp = cur->right;
                TreeNode* findParent;
                while (tmp->left) {
                    findParent = tmp;
                    tmp = tmp->left;
                }
                if (parent->left == cur) {parent->left = tmp;}
                else {parent->right = tmp;}
                tmp->left = cur->left;
                tmp->right = cur->right;
                findParent->left = nullptr;
            }
        }
        return fake->left;
    }
};