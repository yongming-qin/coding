#include "../common.h"

/**
 * @brief You have a queue of integers, you need to retrieve the first unique integer
 * in the queue.
 * Implement the FirstUnique class.
 * 
 */


struct Node {
    int val;
    Node *pre, *next;
    Node(int val) {
        this->val = val;
        this->pre = nullptr; this->next = nullptr;
    }
};

class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int nu : nums) {
            add(nu);
        }
    }
    
    int showFirstUnique() {
        return dummy->next == nullptr ? -1 : dummy->next->val;
    }
    
    void add(int value) {
        // add node to linked list
        if (existed.count(value) == 0) {
            Node* node = new Node(value);
            existed[value] = node;
            tail->next = node; node->pre = tail;
            tail = node;    
        }
        // delete node of linked list
        else {
            Node* node = existed[value];
            // more than 2 times
            if (node == nullptr) return;
            // the second time
            node->pre->next = node->next;
            if (node->next) node->next->pre = node->pre;
            if (tail == node) tail = node->pre;
            existed[value] = nullptr;
            delete node;
        }
    }
    
    Node* dummy = new Node(-1); // value does not matter
    Node* tail = dummy;
    unordered_map<int, Node*> existed;
    
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */