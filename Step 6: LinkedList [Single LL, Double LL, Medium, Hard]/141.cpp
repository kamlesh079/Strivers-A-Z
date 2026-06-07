// https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode* midNode(ListNode* head, ListNode*& preOfMid){
        ListNode* slow = head;
        ListNode* fast = head;
        preOfMid = NULL;
        while(fast && fast -> next){
            preOfMid = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    ListNode* reverseLL(ListNode* head){
        if(!head || !head -> next) return head;

        ListNode* newHead = reverseLL(head -> next);

        head -> next -> next = head;
        head -> next = NULL;

        return newHead;

    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head ->next) return true; // NULL or only head

        ListNode* preOfMid = NULL;
        ListNode* mid = midNode(head, preOfMid);

        // detach
        preOfMid -> next = NULL;

        // new Heads
        ListNode* head1 = head;
        ListNode* head2 = reverseLL(mid);

        while(head1 && head2){
            if(head1 -> val != head2-> val) return false;
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        return true;
    }
};