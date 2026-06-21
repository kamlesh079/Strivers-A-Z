

// Method 1: Brute Force
int celebrity(vector<vector<int>>& mat) {

    int n = mat.size();

    for(int i = 0; i < n; i++) {

        bool celeb = true;

        for(int j = 0; j < n; j++) {

            if(i == j)
                continue;

            // if the current person knows someone then he can't be a celebrity
            if(mat[i][j] == 1){
                celeb = false;
                break;
            }

            // if the current person is not known by someone then he can't be a celebrity
            if(mat[j][i] == 0) {
                celeb = false;
                break;
            }
        }

        if(celeb)
            return i;
    }

    return -1;
}

// Method 2: Stack O(n) time complexity and O(n) space complexity
class Solution {
	public:
	int celebrity(vector<vector<int>> & mat) {
		
		int n = mat.size();
		
		stack<int> st;
		
		// Push everyone
		for (int i = 0; i < n; i++)
			st.push(i);
		
		// Find candidate
		while (st.size() > 1) {
			int A = st.top();
			st.pop();
			
			int B = st.top();
			st.pop();
			
			if (mat[A][B])
				st.push(B); // A knows B -> A dies
			else
				st.push(A); // A doesn't know B -> B dies
			
		}
		int candidate = st.top();
		 
		// Candidate's Row Check -> if candidate knows any one ? -> false || if candidate is know no one -> true
		for (int j = 0; j < n; j++) {
			if (candidate != j && mat[candidate][j] == 1) // if candidate knows any one
				return - 1;
		}
		
		// Candidate's Column Check -> if any one who does not know -> false || if evryone knows -> true
		for (int i = 0; i < n; i++) { 
			if (i != candidate && mat[i][candidate] == 0) // if
				return - 1;
		}
		return candidate;
		
	}
};

// Method 3: Optmal Solution O(n) time complexity and O(1) space complexity
class Solution {
	public:
	int celebrity(vector<vector<int>> & mat) {
		
		int n = mat.size();
		
		int candidate = 0; // let say
		for (int i = 1; i < n; i++) {
			// if candidate knows i -> then it is sure that candidate is not celeb
			// and i maybe not sure
			
			// We are NOT finding the celebrity here.
			// We are only eliminating people who definitely cannot be celebrities.
			if (mat[candidate][i])
				candidate = i;
			
			// else -> candidate doesn't know i
			// => i cannot be celebrity
			// because celebrity must be known by everyone
			//
			// current candidate survives
		}
		
		// Candidate's Row Check -> if candidate knows any one ? -> false || if candidate is know no one -> true
		for (int j = 0; j < n; j++) {
			if (candidate != j && mat[candidate][j] == 1) // if candidate knows any one
				return - 1;
		}
		
		// Candidate's Column Check -> if any one who does not know -> false || if evryone knows -> true
		for (int i = 0; i < n; i++) {
			if (i != candidate && mat[i][candidate] == 0) // if
				return - 1;
		}
		return candidate;
		
	}
};