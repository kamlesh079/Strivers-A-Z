// https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1


// ######### Stack using Linked List ############

// Time Complexity: O(1) for push(), pop() and peek() operations. O(n) for size() operation.

// We used head of the linked list as the top of the stack. So, all operations are O(1) except size() which is O(n) because we have to traverse the whole linked list to count the number of nodes. We can optimize size() by maintaining a count variable that gets updated on push and pop operations, but that would require extra space for the count variable.

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
class myStack {
    Node* top;
  public:
    myStack() {
        // Initialize your data members
        top = nullptr;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top == nullptr;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* node = new Node(x);
        node -> next = top;
        top = node;
    }

    void pop() {
        // Removes the top element of the stack
       if(isEmpty()) return;
       
        Node* temp = top;
        top = top -> next;
        delete temp;
       
    }

    int peek() {
        // Returns the top element of the stack
        if(top != nullptr) return top -> data;
        // If stack is empty, return -1
        return -1;
    }

    int size() {
        // Returns the current size of the stack.
        int count = 0;
        Node* it = top;
        while(it){
            count++;
            it = it -> next;
        }
        return count;
    }
};