class Solution {
public:
//    void moveZeroes(vector<int>& nums) {
//     int n = nums.size();


//     int numZeroes = 0;
//     for (int i = 0; i < n; i++) {
//         numZeroes += (nums[i] == 0);
//     }


//     vector<int> ans;
//     for (int i = 0; i < n; i++) {
//         if (nums[i] != 0) {
//             ans.push_back(nums[i]);
//         }
//     }

//     while (numZeroes--) {
//         ans.push_back(0);
//     }

 
//     for (int i = 0; i < n; i++) {
//         nums[i] = ans[i];
//     }
       
// }
    void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    // If the current element is not 0, then we need to
    // append it just in front of last non 0 element we found. 
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
 	// After we have finished processing new elements,
 	// all the non-zero elements are already at beginning of array.
 	// We just need to fill remaining array with 0's.
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}
};