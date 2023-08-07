class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size()==0) { return -1;}
        
        int pivot = findMin(nums);
        
        int left = 0 ;
        int right = nums.size()-1;
        
        if(target >= nums[pivot] && nums[right] >= target) {
            return binarysearch(nums,pivot,right,target);
        } else {
            return binarysearch(nums,0,pivot-1,target);
        }
        

     return -1;
   

     }
    
        int findMin(vector<int>& nums) {
        
        if(nums.size()==0){return -1;}
        
        int start = 0;
        int end = nums.size()-1;
        
        while(start < end) {
            
            int mid = start + (end-start)/2;
            
            if(nums[mid]>nums[end]) {
                start = mid+1;
            } else{
                end = mid;
            }
        }
            return start;
    }
    
                int binarysearch(vector<int> arr,int start, int end,int target){

    while(start<=end){
    int mid=start +(end-start)/2;

    if(arr[mid]==target){
        return mid;
    }
    else if(target>arr[mid]){
        start=mid+1;
    }
    else{
        end=mid-1;
    }

    }
    return -1;
}

};
    
    
    
    

    
    
    
    
    
    
    
    
    
//     {      if(nums.size()==0){return -1;}
        
//         int pivot = findpivot(nums);
//         int size = nums.size();
        
//         if(pivot==-1) {
//             return binarysearch(nums ,0,size-1, target);
//         } else if(nums[pivot] == target) {
//             return pivot;
//         } else if(nums[0] > target) {
//             return binarysearch(nums,pivot+1,size-1,target);
//         } else {
//             return binarysearch(nums,0,pivot -1,target);
//         }
            
        
//     }
    

        
//   int findpivot(vector<int> &nums){

//     int start=0;
//     int end=nums.size()-1;
                                      
//     while(start<=end){
//         int mid=start +(end-start)/2;
          
//         if(mid < end && nums[mid]>nums[mid+1]){
//             return mid;
//         }
//         if(mid > start && nums[mid]<nums[mid-1]){
//             return mid-1;
//         }
//         if(nums[start]>nums[mid]){
//             end=mid-1;
//         }
//         else{
//             start=mid+1;
//         }
//     } 

//     return -1;
// }