class Solution {
public:
    int missingNumber(vector<int>& nums) {
         
           int i =0;
           while(i<nums.size()) {
               
            int correctindex=nums[i];
            
            if(nums[i] < nums.size() && i!=correctindex) {
                swap(nums[i],nums[correctindex]);
            } else{
                i++;
            }
            
        }
        
        for(int index=0; index<nums.size(); index++) {
            if(nums[index]!=index){
                return index;
            }
        }
        
        
        return nums.size();
    }
};