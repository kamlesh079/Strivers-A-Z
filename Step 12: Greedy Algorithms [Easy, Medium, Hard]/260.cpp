// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution {
	public:
	double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
		vector<pair<double, pair<int, int>> > items;
		
		for (int i = 0; i < val.size(); i++) {
			double ratio = (double) val[i] / wt[i];
			items.push_back({ratio, {val[i], wt[i]}});
		}
		sort(items.begin(), items.end(), greater<>());
		
		double ans = 0;
		
		for(int i = 0; i < items.size(); i++){
		    
		    int value = items[i].second.first;
		    int weight = items[i].second.second;
		    
		    if(weight <= capacity){
		        ans += value;
		        capacity -= weight;
		    }
		    else{
		        ans += items[i].first * capacity;
		        break;
		    }
		}
		return ans;
		
	}
};
