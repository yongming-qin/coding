#include "../common.h"

/**
 * @brief Given a binary tree and a sequence of queries, each query represents
 * on node in the tree. Find the tree depth after removing the query node for the
 * whole sequence.
 * 
 */












class Mine2 {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        // val : left depth, right depth
        unordered_map<int, vector<int>> recordMap;
        // val : {farther, left 0 or right 1}
        unordered_map<int, pair<int,int>> fartherMap;
        dfs(root, recordMap, fartherMap);
        
        vector<int> res;
        for (int q : queries) {
            res.push_back(checkDepth(root->val, q, recordMap, fartherMap));
            
        }
        return res;
    }
    
    int checkDepth(int rootVal, int q,
                   unordered_map<int, vector<int>> &recordMap,
                   unordered_map<int, pair<int,int>> &fartherMap)
    {
        auto [farther, position] = fartherMap[q];
        int res = -1;
        while (true) { // at least run once
            vector<int> record = recordMap[farther]; // left ,right
            record[position] = res; // Important
            res = max(record[0], record[1]) + 1;
            
            if (farther == rootVal) break;
            position = fartherMap[farther].second; // before the next
            farther = fartherMap[farther].first;
            
        }
        
        return res;
    }
    
    // height of this root
    int dfs(TreeNode* root, unordered_map<int, vector<int>> &recordMap,
           unordered_map<int, pair<int,int> > &fartherMap)
    {
        if (root == nullptr) return -1; // Important
        
        int left = dfs(root->left, recordMap, fartherMap);
        if (root->left) fartherMap[root->left->val] = {root->val, 0};
        int right = dfs(root->right, recordMap, fartherMap);
        if (root->right) fartherMap[root->right->val] = {root->val, 1};
        
        recordMap[root->val] = {left, right};
        
        return max(left, right) + 1;
    }
};




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
class Mine {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        vector<int> ans;
        for (int q : queries) {ans.push_back(depth(root, q));}
        return ans;
    }
    
    int depth(TreeNode* root, int query) {
        queue<TreeNode*> qu;
        qu.push(root);
        int res = -1;
        while (qu.size()) {
            int n = qu.size();
            while (n--) { // Remember
                auto cur = qu.front(); qu.pop();
                if (cur->left && cur->left->val != query) qu.push(cur->left);
                if (cur->right && cur->right->val != query) qu.push(cur->right);
            }
            ++res;            
        }
        return res;        
    }
};