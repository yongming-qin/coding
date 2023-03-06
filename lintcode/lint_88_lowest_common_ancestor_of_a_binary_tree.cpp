#include "common.h"


/**
 * @brief 
 * Given a binary tree and values of two nodes, find the lowest common ancestor of
 * the two nodes.
 * 
 * 
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
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        TreeNode* ans = nullptr;
        dfs(root, A, B, ans);
        return ans;
    }


    // 00 : not found; 01 : A found; 10 : B found; 11 : all found
    int dfs(TreeNode* root, TreeNode* A, TreeNode* B, TreeNode* &ans) {
        // stop the traverse if both are found
        if (root == nullptr || ans != nullptr) return 0;

        int left = dfs(root->left, A, B, ans);
        int right = dfs(root->right, A, B, ans);
        int result = left | right;
        if (root == A) {result |= 1;}
        if (root == B) {result |= 2;}
        if (result == 3 && ans == nullptr) ans = root;
        return result;
    }
};