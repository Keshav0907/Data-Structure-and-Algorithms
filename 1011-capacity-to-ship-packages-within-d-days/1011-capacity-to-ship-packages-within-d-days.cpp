class Solution {
public:
    
    bool canShip(vector<int> weights,int days,int k) {
        
//         int count = 1;
//         int sum = 0;
//         for(int i=0; i<weights.size(); i++) {
           
            
//                 sum +=weights[i];
//             if(sum > k){
//                 count++;
//                 sum = weights[i];
//             }
            
            
//         }
        
//         return count<=k;
         int daysNeeded = 1, currentLoad = 0;
        for (int weight : weights) {
            currentLoad += weight;
            if (currentLoad > k) {
                daysNeeded++;
                currentLoad = weight;
            }
        }

        return daysNeeded <= days;
        
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int maxi = 0;
        int sum = 0;
        for(int i=0; i<weights.size(); i++) {
            sum += weights[i];
            maxi = max(weights[i],maxi);
        }
        
        int left = maxi;
        int right = sum;
        int ans;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(canShip(weights,days,mid)) {
                ans = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};