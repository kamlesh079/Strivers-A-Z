// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // # slow fast Method
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(slow == fast) return true;
        }
        return false;

        // # Using Hash Map
        ListNode* curr = head;
        unordered_map<ListNode*, bool> mp;
        while(curr != NULL){
            // Map Opr
            if(true == mp[curr]) 
                return true; // there is cycle
            else mp[curr] = true;

            curr  = curr->next;
        }
        return false; // no cycle
    }
};