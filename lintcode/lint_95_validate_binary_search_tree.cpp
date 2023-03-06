#include "common.h"


/**
 * @brief 
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Yongming
 * 1. inorder traverse
 * 
 */

// Yongming

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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        TreeNode *pre = nullptr;
        return inorder(root, pre);
    }

    bool inorder(TreeNode *root, TreeNode* &pre) {
        if (root == nullptr) return true;
        
        if (!inorder(root->left, pre)) return false;
        if (pre && pre->val >= root->val) return false;
        pre = root;
        if (!inorder(root->right, pre)) return false;
        return true;
    }
};