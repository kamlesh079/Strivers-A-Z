// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        
        for(int i=0; i<arr.size(); i++) {
            int val = arr[i];
            pq.push(val);
        }
        
        long long cost = 0;
        
        while(pq.size() != 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            
            long long sum = first + second;
            
            cost = cost + sum;
            
            pq.push(sum);
        }
        return cost;
        
    }
};