// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Insertion
        if(maxheap.size() == 0 || num < maxheap.top())
            maxheap.push(num);
        else 
            minheap.push(num);

        // Balance -> both can have equal or maxheap can have one extra 
        if(maxheap.size() > minheap.size() + 1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(maxheap.size() < minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }

    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size())
            return (maxheap.top() + minheap.top()) / 2.0;
        return (double)maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */