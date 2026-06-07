// https://leetcode.com/problems/sort-list/

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
    ListNode* midNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow; // node before mid;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* ans = new ListNode(-1);
        ListNode* it = ans;
        
        while(list1 && list2){
            int a = list1 -> val;
            int b = list2 -> val;

            if(a <= b){
                it -> next = list1;
                it = list1;
                list1 = list1 -> next;
            }
            else{
                it -> next = list2;
                it = list2;
                list2 = list2 -> next;
            }
        }
        if(list1) it -> next = list1;
        if(list2) it -> next = list2;

        return ans -> next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next) return head;

        ListNode* mid = midNode(head);

        ListNode* left = head;
        ListNode* right =  mid -> next;

        mid -> next = nullptr;

        ListNode* list1 = sortList(left);
        ListNode* list2 = sortList(right);

        ListNode* merged = merge(list1, list2);

        return merged;
    }
};