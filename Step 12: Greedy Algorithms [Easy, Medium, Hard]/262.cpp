// https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        // int twenty = 0; // do we need ?  No! as we can get max coin is 20 so for
        // change we need coins that is less than 20 for the change
        for (int x : bills) {
            if (x == 5)
                five++;
            else if (x == 10) {
                if (five == 0)
                    return false;
                five--;
                ten++;
            } else {
                if (ten > 0 && five > 0) {
                    five--;
                    ten--;
                } else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};