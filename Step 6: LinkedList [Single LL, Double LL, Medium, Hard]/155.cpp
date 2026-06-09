// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
    Node* merge(Node* list1, Node* list2){
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        if(list1 -> data < list2 -> data){
            list1 -> bottom = merge(list1 -> bottom, list2);
            return list1;
        }
        list2 -> bottom = merge(list1, list2 -> bottom);
        return list2;
    }
    Node *flatten(Node *root) {
        if(!root || !root -> next) return root;
        
        root -> next = flatten(root -> next);
        root = merge(root, root -> next);
        
        return root;
        
    }
};