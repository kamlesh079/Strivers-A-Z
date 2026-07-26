// https://leetcode.com/problems/word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());



        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()){
            auto[word, dist] = q.front();
            q.pop();

            if(word == endWord) 
                return dist;

            for(int i = 0; i < word.size(); i++){
                char org_char = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(ch == org_char)
                        continue;
              
                    word[i] = ch;
        
                    if(st.find(word) != st.end()){
                        q.push({word, dist + 1});
                        st.erase(word);
                    }
                }

                word[i] = org_char;
            }
        }
        return 0;

    }
};