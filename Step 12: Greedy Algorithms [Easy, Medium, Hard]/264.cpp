// https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

class Solution {
	public:
	struct Meeting {
		int start;
		int end;
		int index;
		Meeting(int s, int e, int i) : start(s), end(e), index(i) {};
	};
	class cmp {
		public:
		bool operator() (const Meeting& a, const Meeting& b) {
			if (a.end == b.end)
				return a.index < b.index;
			return a.end < b.end;
		}
	};
	vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
		vector<Meeting> meetings;
		
		for (int i = 0; i < s.size(); i++) {
			meetings.push_back(Meeting(s[i], f[i], i + 1)); // why + 1 ?? index 1 based 
		}
		sort(meetings.begin(), meetings.end(), cmp());
		
		vector<int> ans;
		int lastEnd = -1;
		
		for(auto& meeting : meetings){
		    if(meeting.start > lastEnd){
		        ans.push_back(meeting.index);
		        lastEnd = meeting.end;
		    }
		}
		sort(ans.begin(), ans.end());
		return ans;
		
	}
};
