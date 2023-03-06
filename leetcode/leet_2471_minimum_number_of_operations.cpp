#include "../common.h"

/**
 * @brief Given the root of a binary tree with unique values,
 * you can choose any two nodes at the same level and swap their values in one operation.
 * Return the minimum number of operations needed to make the values at each level sorted.
 * 
 * 
 * 
 */

int minimumOperations(TreeNode* root) {
    int res = 0;
    vector<TreeNode*> qu{root};
    while (qu.size()) {
        vector<TreeNode*> qu1;
        vector<int> vals, ids(qu.size());
        for (auto node : qu) {
            vals.push_back(node->val);
            if (node->left != nullptr) qu1.push_back(node->left);
            if (node->right != nullptr) qu1.push_back(node->right);

        }

        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return vals[i] < vals[j];
        });
        for (int i = 0; i < ids.size(); ++i) {
            for (; ids[i] != i; ++res) {
                swap(ids[i], ids[ids[i]]);
            }
        }
        swap(qu, qu1);

    }
    return res;



}