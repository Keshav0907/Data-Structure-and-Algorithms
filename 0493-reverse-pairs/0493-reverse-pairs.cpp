class Solution {
public:
    
    void merge(vector<int> &nums,int start,int end) {
        int i = start;
        int mid = (start+end)/2;
        int j = mid+1;
        vector<int> temp;
        
        while(i<=mid && j<=end) {
            
            if(nums[i]>=nums[j]) {
                temp.push_back(nums[j]);
                j++;
            } else {
                temp.push_back(nums[i]);
                i++;
            }
            
        }
        
        while(i<=mid) {
            temp.push_back(nums[i]);
            i++;
        }
        
        while(j<=end) {
            temp.push_back(nums[j]);
            j++;
        }
        
        for(int i=start; i<=end; i++) {
            nums[i] =  temp[i-start];
        }
        
    }
      
    int countPairs(vector<int> &nums,int start,int mid,int end) {
        
        int right = mid+1;
        int count = 0;
        for(int i=start; i<=mid; i++) {
            
            while(right<=end && nums[i] > (long long) 2*nums[right]) right++;
            
            count += (right-(mid+1));
            
        }
        
        return count;
        
    }
    
    int mergeSort(vector<int> &nums,int start,int end) {
        
        int count = 0;
        if(start >= end) return count; 
        int mid = (start+end)/2;
        count += mergeSort(nums,start,mid);
        count += mergeSort(nums,mid+1,end);
        count += countPairs(nums,start,mid,end);
        merge(nums,start,end);
        return count;
        
    }
       
    int reversePairs(vector<int>& nums) {
        
        return mergeSort(nums,0,nums.size()-1);
        
        
    }
};