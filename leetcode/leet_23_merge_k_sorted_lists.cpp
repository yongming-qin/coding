#include "../common.h"

/**
 * @brief 
 * 
 * 
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        // minimum heap
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for (ListNode* node : lists) {
            if (node) {pq.push(node);}
        }
        if (pq.empty()) return nullptr; // Yongming Forgot
        
        ListNode* ans = pq.top();
        ListNode* pre = nullptr;
        while (pq.size()) {
            ListNode* cur = pq.top(); pq.pop();
            if (cur->next != nullptr) pq.push(cur->next);
            // update pre
            if (pre == nullptr) {pre = cur; continue;}
            pre->next = cur;
            pre = cur; // Yongming Forgot
        } // no need to change last node->next
        
        return ans;
    }
};







