class Solution {
public:
    
     bool canEat(vector<int> piles,int h,int k) {
         
        long int totalHrs=0;
         
         for(int i=0; i<piles.size(); i++) {
             totalHrs += ceil((double)piles[i]/k);
         }
        
        return totalHrs <= h;
         
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxElement = INT_MIN;
        int minElement = INT_MAX;
        
        for(int i=0; i<piles.size(); i++) {
            maxElement = max(maxElement,piles[i]);
        }
        
        int left = 1;
        int right = maxElement;
        int ans;
        while(left <= right) {
            
            int mid = left + (right-left)/2;
            if(canEat(piles,h,mid)) {
                ans = mid;
                right = mid - 1;
            } else { 
                left = mid + 1;
            }
             
        }
        
        return ans;
    }
};