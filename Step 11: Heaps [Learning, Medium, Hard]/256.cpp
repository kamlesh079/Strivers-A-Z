// https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

class Solution {
	public:
	vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
		int n = a.size();
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		priority_queue<pair<int, pair<int, int>> > pq;
		set<pair<int, int>> visited;
		
		pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
		visited.insert({n - 1, n - 1}); // {i, j}
		
		vector<int> ans;
		
		while (k > 0) {
			auto curr = pq.top();
			pq.pop();
			
			int sum = curr.first;
			int i = curr.second.first;
			int j = curr.second.second;
			
			ans.push_back(sum);
			k--;
			
			//  Case1
			if (i - 1 >= 0 && !visited.count({i - 1, j})) {
				pq.push({a[i - 1] + b[j], {i - 1, j}});
				visited.insert({i - 1, j});
			}
			// Case2
			if (j - 1 >= 0 && !visited.count({i, j - 1}))
				pq.push({a[i] + b[j - 1], {i, j - 1}});
			visited.insert({i, j - 1});
		}
		return ans;
		
	}
};
