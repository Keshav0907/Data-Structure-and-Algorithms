class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int total = 0;
        
        int i=0;
        int j=0;
        int sum = 0;
        while(j < arr.size()) {
            sum += arr[j];
            
            if(j-i+1==k) {
                if(sum/k >= threshold) {
                    total++;
                }
                sum -= arr[i];
                i++;
            }
            j++;
        }
        
        
        return total;
    }
};