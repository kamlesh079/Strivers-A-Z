// https://leetcode.com/problems/hand-of-straights/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        // Total cards must be divisible by groupSize
        if (n % groupSize != 0)
            return false;

        unordered_map<int, int> map;
        for (int x : hand)
            map[x]++;

        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto it : map)
            heap.push(it.first);

        while (!heap.empty()) {

            int start = heap.top();
            for (int i = start; i < groupSize + start; i++) {
                // Missing card
                if (map[i] == 0)
                    return false;

                map[i]--;

                if (map[i] == 0) {

                    if (heap.top() != i)
                        return false;

                    heap.pop();
                }
            }
        }
        return true;
    }
};