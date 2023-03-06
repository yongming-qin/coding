



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> seq;
        inorder(root, seq);
        if (seq.size() < 2) return false;
        
        int start = 0, end = seq.size() - 1;
        while (start < end) {
            int s = seq[start] + seq[end];
            if (s > k) --end;
            else if (s < k) ++start;
            else {return true;}
        }
        return false;
    }
    
    void inorder(TreeNode *root, vector<int> &seq) {
        if (root == nullptr) return;
        
        inorder(root->left, seq);
        seq.push_back(root->val);
        inorder(root->right, seq);
    }
};