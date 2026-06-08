// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // single element
        if(head -> next == NULL) head;

        int len = getLength(head);
        if(len < k) return head;
        
        ListNode* pre = NULL;
        ListNode* curr = head;
        int i = 0;
        while(i < k){
            ListNode* nextNode = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = nextNode;
            i++;
        }
        if(curr){
            ListNode* newHead = reverseKGroup(curr, k);
            head -> next = newHead;
        }
        return pre;
    }
};