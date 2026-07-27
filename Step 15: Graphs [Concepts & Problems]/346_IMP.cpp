// https://leetcode.com/problems/word-ladder-ii/

https://www.geeksforgeeks.org/problems/word-ladder-ii/1

// ---------------- Using BFS (Simple and Easy to Understand) (Interview Friendly) ----------------
class Solution {
	public:
	vector<vector<string>> findSequences(vector<string> &words, string &s, string &e) {
		unordered_set<string> st(words.begin(), words.end());
		
		queue<vector<string>> q;
		
		q.push({s});
		st.erase(s); // used on level 0
		
		vector<vector<string>> ans;
		
		while (!q.empty()) {
			int size = q.size();

			unordered_set<string> used;
			
			bool found = false;
			
			while (size--) {
				auto vec = q.front();
				q.pop();
				
				string lastWord = vec.back();
				
				if (lastWord == e) {
					found = true;
					ans.push_back(vec);
					continue;
				}
				
				for (int i = 0; i < lastWord.size(); i++) {
					
					char org = lastWord[i];
					
					for (char ch = 'a'; ch <= 'z'; ch++) {
						
						if (ch == org)
							continue;
						
						lastWord[i] = ch;
						
						if (st.find(lastWord) != st.end()) {
							
							used.insert(lastWord);
							
							vec.push_back(lastWord);
							q.push(vec);
							
							vec.pop_back(); // Backtrack
						}
					}
					lastWord[i] = org;
				}
			}
			// Level ends
			// remove all used words in this level
			for (string word : used) {
				st.erase(word);
			}
			
			// Since BFS is level-wise, this level contains all shortest paths
			if (found)
				break;
		}
		return ans;
	}
};

// ---------------- BFS Strivers (Same but more Elegant) ----------------
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<vector<string>> q;

        vector<string> used;

        q.push({beginWord});

        int level = 0;

        vector<vector<string>> ans;

        while (!q.empty()) {
            auto vec = q.front();
            q.pop();

            // delete words used in prev level
            if (vec.size() > level) { // if true means this vector came from prev level so delete the word in used till now
                level++;
                for (string& word : used)
                    st.erase(word);
                used.clear(); // after
            }

            string word = vec.back();

            if (word == endWord) {
                if (ans.size() == 0 || ans[0].size() == vec.size())
                    ans.push_back(vec);
            }
            for (int i = 0; i < word.size(); i++) {
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word) > 0) {
                        // Check if the word is present in the wordList and
                        // push the word along with the new sequence in the
                        // queue.
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited on the level
                        used.push_back(word);

                        vec.pop_back(); // backtrack 
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};


// Note: Above Code will Give MLE on Leetcode but not on GFG. So, we can use the below code to avoid MLE on Leetcode.
// ---------------- Optimal BFS (child -> parent map) ----------------
class Solution {
    unordered_map<string, vector<string>> parents;
    unordered_map<string, int> level;
    vector<vector<string>> ans;
    
    void dfs(string word, string& beginWord, vector<string>& path){
        if(word == beginWord){
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for(string str: parents[word]){
            path.push_back(str);
            dfs(str, beginWord, path);
            path.pop_back(); // bactrack;
        }

    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not in st, then early exit
        if (!st.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int currLevel = level[word];

            string temp = word;

            for (int i = 0; i < temp.size(); i++) {
                char original = temp[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (!st.count(temp))
                        continue;

                    // First time visiting this word
                    if (!level.count(temp)) {
                        level[temp] = currLevel + 1;
                        q.push(temp);
                        parents[temp].push_back(word);
                    }
                    // Same shortest distance
                    else if (level[temp] == currLevel + 1) {
                        parents[temp].push_back(word);
                    }
                }

                temp[i] = original;
            }
        }

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);


        return ans;
    }
};


// ---------------- Optimal BFS (parent -> child) ----------------
class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> level;

    void dfs(string word, string &endWord, vector<string> &path) {
        if (word == endWord) {
            ans.push_back(path);
            return;
        }

        for (auto &next : adj[word]) {
            path.push_back(next);
            dfs(next, endWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        int len = beginWord.size();

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            string temp = word;

            for (int i = 0; i < len; i++) {
                char original = temp[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (!dict.count(temp))
                        continue;

                    if (!level.count(temp)) {
                        level[temp] = level[word] + 1;
                        q.push(temp);
                        adj[word].push_back(temp);
                    } else if (level[temp] == level[word] + 1) {
                        adj[word].push_back(temp);
                    }
                }

                temp[i] = original;
            }
        }

        if (!level.count(endWord))
            return {};

        vector<string> path = {beginWord};
        dfs(beginWord, endWord, path);

        return ans;
    }
};