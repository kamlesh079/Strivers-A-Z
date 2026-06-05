// Reverse Every Word in A String

#include <iostream>
#include <vector>

using namespace std;

string reverseWords(string &s) {
    int n = s.size();

    // Remove extra spaces in-place
    int i = 0, j = 0;

    while (j < n) {
        while (j < n && s[j] == ' ') j++; // skip spaces

        while (j < n && s[j] != ' ')
            s[i++] = s[j++];              // copy word

        while (j < n && s[j] == ' ') j++; // skip spaces after word

        if (j < n) s[i++] = ' ';          // keep one space
    }

    s.resize(i);

    // Reverse each word in-place
    int start = 0;
    for (int end = 0; end <= s.size(); end++) {
        if (end == s.size() || s[end] == ' ') {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }

    return s;
}

int main() {
    string s = "  hello   world   cpp  ";
    cout << reverseWords(s);
}