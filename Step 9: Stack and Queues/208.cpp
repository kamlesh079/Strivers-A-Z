// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

class Solution {
	public:
	int prec(char ch) {
		if (ch == '^')
			return 3;
		else if (ch == '/' || ch == '*')
			return 2;
		else if (ch == '+' || ch == '-')
			return 1;
		return - 1;
	}
	string infixToPostfix(string& s) {
		stack<char> st;
		string postfix = "";
		for (char ch : s) {
			if (isalnum(ch))
				postfix += ch;
			else if (ch == '(')
				st.push(ch);
			else if (ch == ')') {
				while (!st.empty() && st.top() != '(') {
					postfix += st.top();
					st.pop();
				}
				st.pop(); // remove '('
			}
			else {
				while (!st.empty() &&
				((prec(st.top()) > prec(ch)) ||
				(prec(st.top()) == prec(ch) && ch != '^'))) {
					postfix += st.top();
					st.pop();
				}
				st.push(ch);
			}
		}
		while(!st.empty()) {
            postfix += st.top();
            st.pop();
        }
		return postfix;
		
	}
};
