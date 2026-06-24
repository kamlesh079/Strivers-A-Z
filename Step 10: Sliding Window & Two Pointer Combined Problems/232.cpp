// 

// 1. Brute Force Approach
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int maxFruits = 0;

        for (int start = 0; start < fruits.size(); ++start) {

            unordered_map<int, int> basket;

            int currentCount = 0;

            for (int end = start; end < fruits.size(); ++end) {

                basket[fruits[end]]++;

                // if unique fruits in basket exceed 2, break the loop
                if (basket.size() > 2) {
                    break;
                }

                currentCount++;
            }

            maxFruits = max(maxFruits, currentCount);
        }
        return maxFruits;
    }
};

// 2. Sliding Window Approach (More Optimized but not optimal)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> mp;
        int ans = 0;
        int left = 0;

        for(int right = 0; right < fruits.size(); right++){

            mp[fruits[right]]++;

            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// 3. Optimal Approach (Sliding Window with Two Pointers)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        // last two fruits
        int lastFruit = -1;
        int secondLastFruit = -1;

        int ans = 0;
        int lastFruitStreak = 0; // count of last fruit streak
        int currLen = 0;

        for(int fruit : fruits){
            if(fruit == lastFruit || fruit == secondLastFruit)
                currLen++;
            else
                currLen = lastFruitStreak + 1;
            
            if(fruit == lastFruit)
                lastFruitStreak++;
            else{
                lastFruitStreak = 1;
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }
            ans = max(ans, currLen);
        }
        return ans;
    }
};