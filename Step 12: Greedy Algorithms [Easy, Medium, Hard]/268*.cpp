// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1


// This gives TLE so we use DSU instead of this approach
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int, int>> jobs;
        for(int i = 0; i < deadline.size(); i++){
            jobs.push_back({profit[i], deadline[i]});
        }
        sort(jobs.begin(), jobs.end(), greater<>());
        
        int n = jobs.size();
        
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i].second);
        }
        
        vector<int> slot(maxDeadline + 1, -1);
        
        int total_jobs = 0;
        int total_profits = 0;
        
        for(int i = 0; i < n; i++){
            int p = jobs[i].first;
            int d = jobs[i].second;
            
            for(int j = d; j >= 1; j--){
                if(slot[j] == -1){
                    slot[j] = i;
                    total_jobs++;
                    total_profits += p;
                    break;
                }
            }
        }
        
        return {total_jobs, total_profits};
    }
};

// DSU Approach 
class Solution {
public:
    vector<int> parent;

    // with path compression
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();

        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

        int maxDeadline = 0;
        for (int d : deadline)
            maxDeadline = max(maxDeadline, d);

        maxDeadline = min(maxDeadline, n);

        parent.resize(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++)
            parent[i] = i;

        int totalJobs = 0;
        int totalProfit = 0;

        for (auto &job : jobs) {
            int p = job.first;
            int d = min(job.second, maxDeadline);

            int available = find(d);

            if (available > 0) {
                totalJobs++;
                totalProfit += p;

                // Mark this slot as occupied
                parent[available] = find(available - 1);
            }
        }

        return {totalJobs, totalProfit};
    }
};