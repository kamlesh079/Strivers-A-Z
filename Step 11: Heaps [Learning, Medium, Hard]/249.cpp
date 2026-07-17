// https://leetcode.com/problems/merge-k-sorted-lists/

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

class cmp{
    public:
        bool operator() (ListNode* a, ListNode* b){
            return a -> val > b -> val; // min heap
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(int i = 0; i < lists.size(); i++){
            if(lists[i])
                pq.push(lists[i]);
        }

        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            tail -> next = node;
            tail = node;

            if(tail -> next)
                pq.push(tail -> next);

        }
        return head -> next;
    }
};