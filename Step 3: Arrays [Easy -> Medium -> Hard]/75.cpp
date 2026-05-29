// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
         vector<int> ans(2, 0);

        // Step 1: Mark visited elements
        for (int i = 0; i < arr.size(); i++) {
            int id = abs(arr[i]) - 1;
            if (arr[id] < 0) { // If already negative, it's a duplicate
                ans[0] = abs(arr[i]); // Repeating number
            } else {
                arr[id] = -arr[id]; // Mark as visited
            }
        }

        // Step 2: Find missing element
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 0) {
                ans[1] = i + 1; // Missing number
                break;
            }
        }

        return ans;
    }
};