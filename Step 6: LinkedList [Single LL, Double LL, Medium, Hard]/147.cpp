// https://leetcode.com/problems/intersection-of-two-linked-lists/

// ############### Using Map ###############
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;
        while(headA != NULL){
            mp[headA] = headA -> val;
            headA = headA -> next;
        }
        while(headB != NULL){
            if(mp.count(headB) != 0){
                return headB;
            }
            mp[headB] = headB -> val;
            headB = headB -> next;
        }
        return 0;
    }
};


// ############### Two Pounter Approach ###############

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b){
            a = (a == NULL) ? headB : a -> next;
            b = (b == NULL) ? headA : b -> next;
        }
        return a;
    }
};
// P1: a+c+b, P2: b+c+a.
// Both travel equal distance, so they meet at the intersection or NULL.
