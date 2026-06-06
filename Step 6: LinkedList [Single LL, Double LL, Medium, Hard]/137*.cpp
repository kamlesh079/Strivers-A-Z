// https://leetcode.com/problems/reverse-linked-list/

// # 1st Way
class Solution {
public:
    ListNode* reverseHead(ListNode* pre, ListNode* curr){
        if(curr == NULL) return pre;

        ListNode* nextNode = curr -> next;
        curr -> next = pre;
        pre = curr;
        curr = nextNode;

        return reverseHead(pre, curr);

    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* curr = head;
        return reverseHead(pre, curr);
    }
};

// # 2nd Way
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next) return head;

        ListNode* newHead = reverseList(head -> next);
        
        head -> next -> next = head;
        head -> next = NULL;

        return newHead;

    }
};

