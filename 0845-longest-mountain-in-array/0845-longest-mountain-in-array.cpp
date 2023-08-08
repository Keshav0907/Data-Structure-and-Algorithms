class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        if(n <= 2) {
            return 0;
        }
        
        int longest = 0;
        
        for(int i=1; i<n-1; i++) {
            
            int len = 0;
            
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) {
                len++;
                int left = i;
                int right = i;
                
                while(left >0 && arr[left-1]<arr[left]) {
                    left--;
                    len++;
                }
                
                while(right<n-1 && arr[right] > arr[right+1]) {
                    right++;
                    len++;
                }
                
            }
            
            longest = max(longest,len);
            
        }
        
        return longest;
        
    }
};