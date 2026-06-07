// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

/* Structure of linked list Node
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
    // We can Use iteravtive approach to save callstack space
    Node* reverse(Node* head){
        if(!head || !head -> next) return head;
        
        Node* newHead = reverse(head -> next);
        
        head -> next -> next = head;
        head -> next = NULL;
        
        return newHead;
    }
    Node* addOne(Node* head) {
        
        Node* newHead = reverse(head);
        Node* temp = newHead;
    
        while(temp){
            if(temp -> data == 9){
                temp -> data = 0;
                if(temp -> next == nullptr){
                    Node* carryNode = new Node(1);
                    temp -> next = carryNode;
                    temp = temp -> next;
                }
            }
            else{
                temp -> data++;
                return reverse(newHead);
            }
            temp = temp -> next;
        }
        
        return reverse(newHead);
    }
};