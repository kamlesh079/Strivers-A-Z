// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

// Method 1: Parent → Children
class Solution {
	public:
	bool isMaxHeap(vector<int> &arr) {
		int n = arr.size();
		for (int i = 0; i < n / 2; i++) {
			int left = 2*i + 1;
			int right = 2*i + 2;
			
			if (left < n && arr[left] > arr[i])
				return false;
			
			if (right < n && arr[right] > arr[i])
				return false;
		}
		return true;
		
	}
};

// Method 2: Child → Parent
class Solution {
	public:
	bool isMaxHeap(vector<int> &arr) {
	    int n = arr.size();
		for (int i = 1; i < n; i++) {
			int parent = (i - 1) / 2;
			
			if (arr[parent] < arr[i])
				return false;
		}
		
		return true;
	}
};

