class Solution {
public:
    
    vector<int> ans;
    
    long merge(vector<int> &arr,long start,long end) {
        ans.clear();
        long i=start;
        long mid = (start+end)/2;
        long j = mid+1;
      
        long res = 0;
        
        while(i<=mid && j<=end) {
            
            if(arr[i] >=arr[j]) {
                res += mid-i+1;
                ans.push_back(arr[j]);
                j++;
            } else {
                ans.push_back(arr[i]);
                i++;
            }
            
        }
        
        while(i<=mid){
            ans.push_back(arr[i++]);
        }
        
        while(j<=end){
            ans.push_back(arr[j++]);
        }
        
        int k = 0;
        
        for(int i=start; i<=end; i++) {
            arr[i] = ans[k++];
        }
        
        return res;
    }
    
    long countInversion(vector<int> &nums,long i,long j) {
        
        if(i >= j){
            return 0;
        }
        
        long mid = (i+j)/2;
        long c1 = countInversion(nums,i,mid);
        long c2 = countInversion(nums,mid+1,j);
        long c3 = merge(nums,i,j);
        return c1+c2+c3;
        
    }
    
    bool isIdealPermutation(vector<int>& nums) {
     
        int n = nums.size();
        long localInversion = 0;
        
        for(int i=0; i<n-1; i++) {
            if(nums[i] > nums[i+1]) {
                localInversion++;
            }
        }
        
        long globalInversion = countInversion(nums,0,n-1);
        
    
        
        return localInversion==globalInversion;
        
    }
};