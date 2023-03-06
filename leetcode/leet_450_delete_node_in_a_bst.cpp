#include "../common.h"

/**
 * @brief 
 * 
 * 
 */



class Mine {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy = new TreeNode();
        TreeNode* parent = dummy;
        parent->left = root;
        TreeNode* cur = root;
        // looking for the node
        while (cur) {
            if (key > cur->val) {
                parent = cur;
                cur = cur->right;
            }
            else if (key < cur->val) {
                parent = cur;
                cur = cur->left;
            }
            else break;
        }
        if (cur == nullptr) return dummy->left; 
        
        // remove the node and adjust the tree
        if (cur->right == nullptr) {
            connect(parent, cur, cur->left);
        } else {
            if (cur->right->left == nullptr) {
                cur->right->left = cur->left;
                connect(parent, cur, cur->right);
            } else { // Yongming just change cur->val. easier.
                // find the consequtive next node
                TreeNode* iter = cur->right;
                TreeNode* iterParent;
                while (iter->left) {
                    iterParent = iter;
                    iter = iter->left;
                }
                iterParent->left = iter->right;
                iter->left = cur->left;
                iter->right = cur->right;
                connect(parent, cur, iter);
            }
        }
        
        return dummy->left;
    }
    
    void connect(TreeNode* parent, TreeNode* cur, TreeNode* child) {
        if (parent->left == cur) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }
};



class IterativeSolution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* target = root;
        TreeNode* parent = nullptr;

        // Search node
        while (target != nullptr && target->val != key) {
            parent = target;
            if (key > target->val) target = target->right;
            else target = target->left;
        }
        if (target == nullptr) return root; // not found

        // Case 1 : no children
        if (target->left == nullptr && target->right == nullptr) {
            if (parent == nullptr) return nullptr;
            if (target == parent->left) parent->left == nullptr;
            else parent->right == nullptr;
            return root;
        }

        // Case 2 : one child
            // Case 2.1 : no right child
        if (target->right == nullptr) {
            if (parent == nullptr) return target->left;
            if (target == parent->left) parent->left = target->left;
            else parent->right = target->left;
            return root;
        }
            // Case 2.2 : no left child
        if (target->left == nullptr) {
            if (parent == nullptr) return target->right;
            if (target == parent->left) parent->left = target->right;
            else parent->right = target->right;
            return root;
        }

        // Case 3 : both the child nodes exist
            /* Whenever we delete a node with two children then we replace that node with 
               the leftmost element from the right subtree because to hold the propoerty
               of BST all the elements to the right of the new node will be greater than it
               and all the left ones will be less than it*/

        // Trace to the leftmost element in right subtree
        TreeNode* prev = target;
        TreeNode* p = target->right;
        while (p->left) {
            pre = p; p = p->left;
        }
        target->val = p->val;
        if (p == pre->left) pre->left = p->right;
        else pre->right = p->right;
        return root;
    }




};


class RecursiveSolution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root) {
            if (key < root->val) root->left = deleteNode(root->left, key);
            else if (key > root->val) root->right = deleteNode(root->right, key);
            else {
                if (!root->left && !root->right) return nullptr;
                if (!root->left || !root->right) return root->left ? root->left : root->right;

                TreeNode* temp = root->left;
                while (temp->right != nullptr) temp = temp->right;
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }
        return root;
    }


};