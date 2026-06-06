// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
       if(!head) return NULL;
       
       Node* curr = head;
       Node* temp = NULL;
       while(curr){
           temp = curr -> prev;
           curr -> prev = curr -> next;
           curr -> next = temp;
           
           head = curr;
           curr = curr -> prev;
       }
        return head;
    }
};