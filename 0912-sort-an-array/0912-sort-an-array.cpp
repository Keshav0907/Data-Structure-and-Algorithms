class Solution {
public:
    
    void merge(vector<int> &arr,int start,int end) {
        
        if(start >= end) {
            return;
        }
        
        vector<int> temp;
        int i=start;
        int mid = (start + end)/2;
        int j = mid + 1;
        
        while(i<=mid && j<=end) {
            
            if(arr[i]<=arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
            
        }
        
        while(i<=mid) {
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j<=end) {
            temp.push_back(arr[j]);
            j++;
        }
        
        int k=0;
        
        for(int i=start; i<=end; i++) {
            arr[i] = temp[k++];
        
        }
        
        
        
    }
    
    
    void sort(vector<int> &arr,int start,int end) {
        
        if(start >= end) {
            return;
        }
        int mid = (start + end)/2;
        sort(arr,start,mid);
        sort(arr,mid+1,end);
        return merge(arr,start,end);
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        sort(nums,0,nums.size()-1);
        
        return nums;
    }
};