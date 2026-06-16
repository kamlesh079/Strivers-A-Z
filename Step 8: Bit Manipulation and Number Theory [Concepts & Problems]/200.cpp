// https://www.geeksforgeeks.org/problems/powx-n/1

class Solution {
	public:
	double fastExpo(double b, int e){
	    if (e == 0)
			return 1;
		
		double half = power(b, e / 2);
		
		if (e & 1)
			return b * half* half;
			
		return half * half;
	}
	double power(double b, int e) {
		if(e < 0){
		    b = 1.0/b;
		    e = -e;
		}
		return fastExpo(b, e);
	}
};
