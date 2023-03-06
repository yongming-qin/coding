#include "../common.h"

/**
 * @brief 
 * 
 * 
 */


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string order;
        inorder(root, order);
        return order;
    }

    inline void inorder(TreeNode* root, string& order) {
        if (!root) return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int)); // bur the int into 4 chars
        for (int i = 0; i < 4; ++i) order.push_back(buf[i]);
        inorder(root->left, order);
        inorder(root->right, order);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos, INT_MIN, INT_MAX);

    }

    inline TreeNode* reconstruct(const string& buffer,
        int& pos, int minValue, int maxValue)
    {
        if (pos >= buffer.size()) return nullptr;

        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue) return nullptr;

        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        // Yongming. This is preorder. If postorder, first right then left.
        node->left = reconstruct(buffer, pos, minValue, value);
        node->right = reconstruct(buffer, pos, value, maxValue);
        return node;
    }





};