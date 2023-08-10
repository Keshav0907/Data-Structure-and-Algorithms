class Solution {
public:
    
    bool isPossible(vector<int> &bloomDay,int m,int k,int val) {
        
        int x = 0;;
        int count = 0;
        for(int i=0; i<bloomDay.size(); i++) {
            
            if(bloomDay[i] <= val) {
              x++;
            } else {
                count += x/k;
                x = 0;
            }
            
        }
        
        count += x/k;
        return count >= m;
        
        
        
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int maxi = INT_MIN;
        for(int i=0; i<bloomDay.size(); i++) {
            maxi = max(bloomDay[i],maxi);
        }        
        
        int low = 1;
        int high = maxi;
        int res = -1;
        while(low <= high) {
            
            int mid = low + (high-low)/2;
            
            if(isPossible(bloomDay,m,k,mid)) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
            
        }
        
        return res;
        
    }
};