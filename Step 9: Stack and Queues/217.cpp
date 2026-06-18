// https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

// In this we have count of NGE (Next Greater Element) for each index and then we return the count for the given indices in the query.(if u want query specific count then just change a little bit in countGreater function and return the count for the given index instead of storing it in cnt array.)
class Solution {
	public:
	void countGreater(vector<pair<int, int>> & arr, int s, int mid, int e, vector<int>& cnt) {
		
		int right = mid + 1;
		
		for (int left = s; left <= mid; left++) {
			
			// move to first element > arr[left]
			while (right <= e && arr[right].first <= arr[left].first)
				right++;
			
			cnt[arr[left].second] += (e - right + 1);
		}
	}
	
	void merge(int s, int mid, int e, vector<pair<int,int>>& arr) {

        vector<pair<int,int>> temp;

        int left = s;
        int right = mid + 1;

        while (left <= mid && right <= e) {
            if (arr[left].first <= arr[right].first)
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        while (left <= mid)
            temp.push_back(arr[left++]);

        while (right <= e)
            temp.push_back(arr[right++]);

        for (int i = s; i <= e; i++)
            arr[i] = temp[i - s];
    }
	
	void mergeSort(int s, int e, vector<pair<int,int>>& arr,
                   vector<int>& cnt) {

        if (s >= e) return;

        int mid = s + (e - s) / 2;

        mergeSort(s, mid, arr, cnt);
        mergeSort(mid + 1, e, arr, cnt);

        countGreater(arr, s, mid, e, cnt);

        merge(s, mid, e, arr);
    }
    
	vector<int> count_NGE(vector<int>& nums, vector<int>& indices) {

        int n = nums.size();

        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        vector<int> cnt(n, 0);

        mergeSort(0, n - 1, arr, cnt);

        vector<int> ans;

        for (int idx : indices)
            ans.push_back(cnt[idx]);

        return ans;
    }
};


// Similar to count of inversion in an array 
class Solution {
	public:
	void mergeSort(vector<pair<int, int>> & arr, int l, int r, vector<int>& cnt){
		if (l >= r)
			return;
		
		int mid = l + (r - l) / 2;
		
		mergeSort(arr, l, mid, cnt);
		mergeSort(arr, mid + 1, r, cnt);
		
		
        // ########## Merge ###########
		vector<pair<int, int>> temp;
		
		int left = l;
		int right = mid + 1;
		
		while (left <= mid && right <= r) {
			
			if (arr[left].first < arr[right].first) {
				
				// All remaining elements in right half
				// are greater than arr[left]
				cnt[arr[left].second] += (r - right + 1);
				
				temp.push_back(arr[left]);
				left++;
			}
			else {
				temp.push_back(arr[right]);
				right++;
			}
		}
		
		while (left <= mid) {
			temp.push_back(arr[left]);
			left++;
		}
		
		while (right <= r) {
			temp.push_back(arr[right]);
			right++;
		}
		
		for (int i = l; i <= r; i++)
			arr[i] = temp[i - l];
	}
	
	vector<int> count_NGE(vector<int>& nums, vector<int>& indices) {
		
		int n = nums.size();
		
		vector<pair<int, int>> arr;
		
		for (int i = 0; i<n; i++)
			arr.push_back({nums[i], i});
		
		vector<int> cnt(n, 0);
		
		mergeSort(arr, 0, n - 1, cnt);
		
		vector<int> ans;
		
		for (int idx : indices)
			ans.push_back(cnt[idx]);
		
		return ans;
	}
};
