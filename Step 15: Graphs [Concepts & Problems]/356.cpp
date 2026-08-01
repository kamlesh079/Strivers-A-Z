// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution {
  public:
    bool buildGraph(unordered_map<char, unordered_set<char>>& adj, 
                    unordered_map<char, int>& indegree, 
                    vector<string>& words){
        
        // Add every unique character
        for(string& word: words){
            for(char ch : word){
                adj[ch];
                indegree[ch];
            }
        }
        
         // Compare adjacent words
        for(int i = 0; i < words.size() - 1; i++){
            string &first = words[i];
            string &second = words[i + 1];
            bool found = false;
            
            int n = min(first.size(), second.size());
            
            for(int i = 0; i < n; i++){
                // First different character determines the ordering
                if(first[i] != second[i]){
                    
                    // Unordered_set is used to abvoid duplicates
                    // Return Value: It returns a std::pair<iterator, bool>.
                    // pair.first is an iterator pointing to the element in the set.
                    // pair.second is a bool (true if inserted successfully, false if it was a duplicate).
                    
                    if(adj[first[i]].insert(second[i]).second)
                        indegree[second[i]]++;
                        
                    found = true;
            
                    break;
                }
            }
            
            if(!found && first.size() > second.size())
                return false;
            
        }
        return true;
    }
    
    string kahn(unordered_map<char, unordered_set<char>>& adj,
                unordered_map<char, int>& indegree) {

        queue<char> q;

        for (auto &it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }

        string order = "";

        while (!q.empty()) {

            char node = q.front();
            q.pop();

            order += node;

            for (char nbr : adj[node]) {

                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        // Cycle exists
        if (order.size() != indegree.size())
            return "";

        return order;
    }
    
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        
        bool respons = buildGraph(adj, indegree, words);
        if(!respons) return "";
        
        return kahn(adj, indegree);
        
    }
};