class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        vector<double> time(speed.size(),0);
        
        for(int i=0; i<speed.size(); i++) {
            time[i] = (double)dist[i]/(double)speed[i];
        }
        sort(time.begin(),time.end());
        
        int ans = 0;
        int currTime=0;
        for(auto min : time) {
         
            if(min <= currTime) {
                break;
            } else{
                ans++;
                currTime++;
            }
        }
        return ans;
    }
};