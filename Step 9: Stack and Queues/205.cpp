// https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

class Node {
	public:
	int data;
	Node* next;
	
	Node(int new_data) {
		data = new_data;
		next = nullptr;
	}
};

class myQueue {
	Node* front = nullptr;
	Node* rear = nullptr;
    
	public:
	myQueue() {
		// Initialize your data members
	}
	
	bool isEmpty() {
		// check if the queue is empty
		return rear == nullptr;
	}
	
	void enqueue(int x) {
		// Adds an element x at the rear of the queue
		// 1. First Element
		Node* node = new Node(x);
		if (rear == nullptr)
			front = rear = node;
		// 2. Normal case
		else {
			rear -> next = node;
			rear = node;
		}
		
	}
	
	void dequeue() {
		if (front == nullptr)
			return;
		Node* temp = front;
		front = front -> next;
		if (front == nullptr)
			rear = nullptr;
		delete temp;
	}
	
	int getFront() {
		// Returns the front element of the queue
		if (front)
			return front -> data;
		// If queue is empty, return -1
		return - 1;
	}
	
	int size() {
		// Returns the current size of the queue.
		int count = 0;
		Node* it = front;
		while (it) {
			count++;
			it = it -> next;
		}
		return count;
	}
};
