// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void insertAtTail(Node* &head, Node* &tail, Node* curr){
        if( head == NULL && tail == NULL){
            head = curr;
            tail = curr;
        }
        else{
            tail -> next = curr;
            tail = curr;
        }
    }
    Node* segregate(Node* head) {
        
        Node* zeroHead = NULL;
        Node* oneHead = NULL;
        Node* twoHead = NULL;
        
        Node* zerotail = NULL;
        Node* onetail = NULL;
        Node* twotail = NULL;
        
        Node* temp = head;
        while( temp != NULL){
            Node* currNode = temp;
            temp = temp -> next;
            
            // Isolating the currNode
            currNode -> next = NULL;
            
            if(currNode -> data == 0 )
                insertAtTail(zeroHead, zerotail, currNode);
            else if(currNode -> data == 1 )
                insertAtTail(oneHead, onetail, currNode);
            else 
                insertAtTail(twoHead, twotail, currNode);
        }
        
        // joining the linked list
        if(zeroHead != NULL) {
            //zero list is non-empty
            if(oneHead != NULL) {
                //one list is non-empty
                zerotail->next = oneHead;
                //merge with 2 wali list
                onetail->next = twoHead;
            }
            else {
                //one list is empty
                zerotail->next = twoHead;
            }
            return zeroHead;
        }
        else {
            //zero List is empty
            if(oneHead != NULL) {
                onetail->next = twoHead;
                return oneHead;
            }
            else {
                return twoHead;
            }
        }
        
    }
};