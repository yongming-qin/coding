#include "../common.h"

/**
 * @brief 
 * 
 * 
 */

// Recursive solution
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* cursor = head;
    for (int i = 0; i < k; i++) {
        if (cursor == nullptr) return head;
        cursor = cursor->next;
    }
    ListNode* cur = head;
    ListNode* pre = nullptr;
    ListNode* nxt = nullptr;
    for (int i = 0; i < k; i++) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    head->next = reverseKGroup(cur, k);
    reture pre;
}

// Iterative solution
ListNode* reverseKGroup2(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* before = dummy;
    ListNode* after = head;
    ListNode* cur = nullptr, pre = nullptr, nxt = nullptr;

    while (true) {
        ListNode* cursor = after;




    }
}

// Iterative solution
// I like this version. First count the length. Then do a for loop of len / k.
// Inside each loop, reverse the linked list.