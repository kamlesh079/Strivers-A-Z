// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string str) {
        int n = str.size();

        // Reverse the entire string first.
        // Example: "the sky is blue" -> "eulb si yks eht"
        reverse(str.begin(), str.end());

        int s = 0; // Start index of the current word in the result
        int e = 0; // Position where the next character will be written

        int i = 0;
        while (i < n) {

            // Skip all extra spaces between words (or leading spaces).
            while (i < n && str[i] == ' ') i++;

            // If only spaces remain, we're done.
            if (i == n) break;

            // Copy the current word to its correct compact position.
            while (i < n && str[i] != ' ')
                str[e++] = str[i++];

            // Reverse the copied word to restore its original character order.
            reverse(str.begin() + s, str.begin() + e);

            // Add a single space after the word.
            str[e++] = ' ';

            // Mark the start of the next word.
            s = e;
        }

        // Remove the trailing space added after the last word.
        // If no words were copied, resize the string to length 0.
        str.resize(e ? e - 1 : 0);

        return str;
    }
};