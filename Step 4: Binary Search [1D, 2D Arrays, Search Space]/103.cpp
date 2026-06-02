// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

class Solution {
  public:
  
    bool isValid(double dist, vector<int> &stations, int k){
        int count = 0;
        for(int i = 1; i < stations.size(); i++){
            int gap = stations[i] - stations[i - 1];
            int station_req = (int)gap / dist;
            if(gap == station_req * dist) station_req--; // when full division
            count += station_req;
        }
        return count > k;
    }
    double minMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        
        double s = 0;
        double e = 0;
        for(int i = 1; i < n; i++){
            e = max(e, (double)(stations[i] - stations[i -1]));
        }
        
        double eps = 1e-6;
        while(e - s > eps){
            double mid = s + (e - s)/2;
            if(isValid(mid, stations, K)){
               e = mid;
            }
            else s = mid;
        }
        return e;
    }
};