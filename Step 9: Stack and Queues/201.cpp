// https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

// Circular Queue implementation in C++
class myQueue {
	int* arr;
	int size;
	int front;
	int rear;
	int count;
	
	public:
	myQueue(int n) {
		arr = new int[n];
		size = n;
		front = -1;
		rear = -1;
		count = 0;
	}
	
	bool isEmpty() {
		return count == 0;
	}
	
	bool isFull() {
		return count == size;
	}
	
	void enqueue(int x) {
		// Queue is full, cannot insert more elements in the queue
		if (isFull())
			return;
		
		// Single Element Insertion
		if (isEmpty())
			front = rear = 0;
		// Normal Case
		else 
			rear = (rear + 1) % size;
		
		arr[rear] = x;
		count++;
	}
	
	void dequeue() {
		// Queue is empty, there is no element to dequeue
		if (isEmpty())
			return;
		
		// Single Element Deletion
		if (count == 1) {
			front = rear = -1;
			count = 0;
		} 
		// Normal Case
		else {
			front = (front + 1) % size;
			count--;
		}
	}
	
	int getFront() {
		// Empty Queue, there is no element at the front
		if (isEmpty())
			return - 1;
		return arr[front];
	}
	
	int getRear() {
		// Empty Queue, there is no element at the rear
		if (isEmpty())
			return - 1;
		return arr[rear];
	}
	
	~myQueue() {
		delete[] arr;
	}
};
