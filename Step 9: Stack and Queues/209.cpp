// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

class Solution {
	public:
	string preToInfix(string pre_exp) {
		int n = pre_exp.size();
		string infix = "";
		stack<string> st;
		for (int i = n - 1; i >= 0; i--) {
			
			char ch = pre_exp[i];

			if (isalnum(ch))
				st.push(string(1, ch));
			else {
				string op1 = st.top();
				st.pop();
				
				string op2 = st.top();
				st.pop();
				
				string temp = "(" + op1 + ch + op2 + ")";
                
                st.push(temp);
			}
		}
		 return st.top();
	}
};
