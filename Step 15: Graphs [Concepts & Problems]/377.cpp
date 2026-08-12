// https://leetcode.com/problems/accounts-merge/

class Solution {
public:
    vector<int> parent, rank;
    int findUPar(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = findUPar(parent[x]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        unordered_map<string, string> emailToName;

        int n = 0;

        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                if (!mp.count(email))
                    mp[email] = n++;
                emailToName[email] = name;
            }
        }

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Now Lets do the union
        for (auto& account : accounts) {
            int first = mp[account[1]];
            for (int i = 2; i < account.size(); i++) {
                int curr = mp[account[i]];
                unionByRank(first, curr);
            }
        }

        unordered_map<int, vector<string>> groups;
        for (auto it : mp) {
            string email = it.first;
            int id = it.second;

            int parent = findUPar(id);

            groups[parent].push_back(email);
        }

        vector<vector<string>> ans;

        for (auto it : groups) {
            int parent = it.first;
            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> account;

            account.push_back(emailToName[emails[0]]);

            for (auto &email : emails)
                account.push_back(email);

            ans.push_back(account);
        }

        return ans;
    }
};