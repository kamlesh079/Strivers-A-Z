// https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

class Solution {
	public:
	string postToPre(string s) {
		string postfix = "";
		stack<string> st;
		
		for (char ch : s) {
			if (isalnum(ch))
				st.push(string(1, ch));
			else {
				string op2 = st.top();
				st.pop();
				
				string op1 = st.top();
				st.pop();
				
				string temp = ch + op1 + op2;
				
				st.push(temp);
			}
		}
		return st.top();
	}
};
