// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        if (!headRef) return nullptr;
        
        Node* it = headRef;
        Node* curr = headRef;
        
        while(curr){
            if(curr -> data != it -> data){
                it -> next = curr;
                curr -> prev = it;
            
                it = it -> next;
            }
            curr = curr -> next;
        }
        it -> next = nullptr;
        return headRef;
    }
};