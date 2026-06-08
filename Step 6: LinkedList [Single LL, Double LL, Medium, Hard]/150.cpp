// https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1


/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* curr = head;
        
        while(curr){
            if(curr -> data == x){
                Node* nextNode = curr->next;
                Node* preNode = curr->prev;
                
                Node* nodeToDelete = curr;
                
                // Case A: Deleting the head node
                if(curr == head){
                    head = nextNode;
                    if(head) head -> prev = nullptr;
                }
                // Case B: Deleting middle or tail node
                else{
                    if(preNode)
                        preNode -> next = nextNode;
                    if(nextNode)
                        nextNode -> prev = preNode;
                }
                
                curr = nextNode;
                
                // free memory
                delete nodeToDelete;
                
            }
            else
                curr = curr -> next;
        }
        return head;
       
        
    }
};