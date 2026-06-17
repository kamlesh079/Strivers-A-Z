// https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1

class Solution {
	public:
	int prec(char ch) {
		if (ch == '^')
			return 3;
		if (ch == '*' || ch == '/')
			return 2;
		if (ch == '+' || ch == '-')
			return 1;
		return - 1;
	}
	
	string infixToPrefix(string &s) {
		// Step 1: Reverse
		reverse(s.begin(), s.end());
		
		// Step 2: Swap brackets
		for (char &ch : s) {
			if (ch == '(')
				ch = ')';
			else if (ch == ')')
				ch = '(';
		}
		
		stack<char> st;
		string postfix = "";
		
		// Step 3: Infix -> Postfix
		for (char ch : s) {
			
			if (isalnum(ch)) {
				postfix += ch;
			}
			
			else if (ch == '(') {
				st.push(ch);
			}
			
			else if (ch == ')') {
				
				while (!st.empty() && st.top() != '(') {
					postfix += st.top();
					st.pop();
				}
				
				if (!st.empty())
					st.pop();
			}
			else { // operator
				
				while (!st.empty() &&
				(prec(st.top()) > prec(ch) ||
				(prec(st.top()) == prec(ch) && ch == '^')))
				{
					postfix += st.top();
					st.pop();
				}
				
				st.push(ch);
			}
		}
		while (!st.empty()) {
			postfix += st.top();
			st.pop();
		}
		// Step 4: Reverse postfix => prefix
		reverse(postfix.begin(), postfix.end());
		
		return postfix;
	}
};
