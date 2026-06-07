// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        // 0 or 1 node -> list becomes empty
        if (!head || !head->next) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* preOfSlow = NULL; // Node before middle

        // Slow reaches middle when fast reaches end
        while (fast && fast->next) {
            preOfSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow = middle node, preOfSlow = node before middle
        ListNode* del = slow;
        preOfSlow->next = del->next;

        del->next = NULL;
        delete del;

        return head;
    }
};