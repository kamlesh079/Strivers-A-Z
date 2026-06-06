// https://www.geeksforgeeks.org/problems/find-length-of-loop/1


/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* detectLoop(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return slow;
        }
        return NULL;
    }
    int lengthOfLoop(Node *head) {
        Node* meet = detectLoop(head);
        // no cycle
        if(!meet) return 0;
        
        int count = 1;
        Node* curr = meet -> next;
        while(curr != meet){
            count++;
            curr = curr -> next;
        }
        
        return count;
    }
};