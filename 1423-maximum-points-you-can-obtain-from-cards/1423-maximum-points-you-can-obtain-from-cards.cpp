class Solution {
public:
    
    int minSum(vector<int> &cardPoints,int k) {
        
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int sum = 0;
        
        while(j < cardPoints.size()) {
            
            sum += cardPoints[j];
            
            if(j-i+1==k) {
                ans = min(ans,sum);
                sum -= cardPoints[i];
                i++;
            }
            
            j++;
        }
            
        return ans;
        
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int s = n - k;
        int sum = 0;
        for(auto el : cardPoints) {
            sum += el;
        }
        
        if(s==0) return sum;
        
        return sum - minSum(cardPoints,s);
    }
};