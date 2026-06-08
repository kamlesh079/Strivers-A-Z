// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        
        Node* right = head;
        while(right -> next) right = right -> next;
        
        Node* left = head;
        while(left != right && right->next != left){
            int sum = left -> data + right -> data;
            
            if(sum == target){
                
                ans.push_back({left -> data, right -> data});
                left = left -> next;
                right = right ->prev;
            }
            else if (sum < target) left = left -> next;
            else right = right -> prev;
        }
        return ans;
        
    }
};