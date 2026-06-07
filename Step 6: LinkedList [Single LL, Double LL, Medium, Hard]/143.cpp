// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Dummy handles edge case when head itself must be removed
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Create a gap of (n + 1) nodes between slow and fast
        // so slow stops at node before the one to delete
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both together until fast reaches the end
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove nth node from end
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        return dummy.next; // New head (may differ if original head was removed)
    }
};