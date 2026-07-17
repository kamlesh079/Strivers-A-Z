// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        for(char task: tasks)
            map[task]++;
        
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        
        for(auto& it: map)
            pq.push({it.second, it.first});
        
        int time = 0;
        
        while(!pq.empty()){
            int cycle = n + 1;

            vector<pair<int, char>> temp;

            while(cycle > 0 && !pq.empty()){
                auto[freq, task] = pq.top();
                pq.pop();

                freq--;
                time++;
                cycle--;

                temp.push_back({freq, task});
            }

            for(auto it: temp){
                if(it.first > 0)
                    pq.push(it);
            }
                
            if(!pq.empty())
                time += cycle;
    
        }
        return time;
    }
};