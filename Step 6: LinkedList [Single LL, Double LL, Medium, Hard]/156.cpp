// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head; // if head is null

        // Creating A -> A'
        Node* it = head;
        while(it){
            Node* cloneNode = new Node(it -> val);
            cloneNode -> next = it -> next;
            it -> next = cloneNode;
            it = it -> next -> next; // Propogate to next node
        }

        // Assigning random pointer
        it = head;
        while(it){
            Node* cloneNode = it -> next;
            cloneNode -> random = it -> random ? it -> random -> next : nullptr;
            it = it -> next -> next; // Propogate to next node
        }

        // removing old nodes
        it = head;
        Node* cloneHead = it -> next;
        while(it){
            Node* cloneNode = it -> next;

            it -> next = it -> next -> next;
            if(cloneNode -> next)
                cloneNode -> next = cloneNode -> next -> next;

            it = it -> next; // Propogate to next node
        }
        return cloneHead;
    }
};