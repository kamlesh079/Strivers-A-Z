// https://www.tryexponent.com/courses/swe-practice/k-messed-array-sort


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> sortKMessedArray( const vector<int>& arr, int k ) 
{
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i <= k; i++){
      pq.push(arr[i]);
    }
    
    vector<int> ans;

    for(int i = k + 1; i < arr.size(); i++){
      ans.push_back(pq.top());
      pq.pop();
      pq.push(arr[i]);
    }

    while(!pq.empty()){
      ans.push_back(pq.top());
      pq.pop();
    }

    return ans;
}

// comment out main() before running tests
int main() {
    // debug your code below
    vector<int> arr = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    int k = 2;
    vector<int> result = sortKMessedArray(arr, k);

    cout << "Sorted KMessed Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}