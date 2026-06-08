// https://leetcode.com/problems/rotate-list/

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
    int getLength(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next) return head; // single or head == nullptr

        int len = getLength(head);
        k = k % len; // effective k
        if(k == 0) return head;

        // Now Lets Rotate
        int pos = len - k - 1;
        ListNode* curr = head;
        for(int i = 0; i < pos; i++){
            curr = curr -> next;
        }

        ListNode* newHead = curr -> next;
        curr -> next = nullptr;

        curr = newHead;
        while(curr -> next) curr = curr -> next;
        curr -> next = head;
        
        return newHead;
    }
};