// https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode* detectLoop(ListNode *head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(slow == fast) return slow;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = detectLoop(head);

        // if no cycle
        if(!fast) return NULL;

        // restart the slow
        ListNode* slow = head;
        
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};

// ############ Mathematical Proof ############

// Let:

// x = distance from head to cycle start.
// y = distance from cycle start to meeting point.
// c = cycle length.

// When slow and fast meet:

// slow distance = x + y
// fast distance = x + y + k*c

// Since fast moves twice as fast:

// 2(x + y) = x + y + k*c

// Therefore:

// x + y = k*c

// or

// x = k*c - y

// This means:

// Distance from head to cycle start (x)

// equals

// Distance from meeting point to cycle start when moving forward around the cycle (k*c - y).

// So:

// slow starts at head and needs x steps to reach cycle start.
// fast starts at meeting point and also needs x steps to reach cycle start (because x = k*c - y).

// If both move one step at a time, they arrive at the cycle start together.