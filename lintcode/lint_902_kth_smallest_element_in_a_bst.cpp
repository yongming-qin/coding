


/**
 * @brief 
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 * 1. dfs inorder search stop at the kth position
 * 2. non recursive way. run next() k times
 * 3. priority_queue<>() k times
 */

/**
 * @brief ANSWER answer
 * 1. traverse. map. quick select
 * 
 */



struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val; 
        this->left = this->right = nullptr;
    }
};

class Solution {
public:

    int kthSmallest(TreeNode *root, int k) {
        int ans;
        dfs(root, k, ans);
        return ans;
    }

    void dfs(TreeNode *root, int k, int &ans) {
        if (root == nullptr || k <= 0) return; 
        dfs(root->left, k, ans);
        k--;
        if (k == 0) ans = root->val;
        dfs(root->right, k, ans);
    }


    


};

/*********** Quick Select ***********/
