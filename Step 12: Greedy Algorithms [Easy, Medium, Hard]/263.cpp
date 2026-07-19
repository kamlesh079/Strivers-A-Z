// https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

class Solution {
	public:
	bool isBalanced(string& s) {
		stack<char> st;
		for (char ch: s) {
			if (ch == '[' || ch == '{' || ch == '(')
				st.push(ch);
			else {
				if (st.empty())
					return false;
				
				char top = st.top();
				if ((top == '[' && ch == ']') ||
				    (top == '{' && ch == '}') ||
				    (top == '(' && ch == ')'))
				st.pop();
				else return false;
				
			}
		}
		return st.empty();
		
	}
};
