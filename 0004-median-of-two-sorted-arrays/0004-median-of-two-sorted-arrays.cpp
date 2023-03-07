class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
//         vector<int> vec;
        
//         int i=0;
//         int j=0;
//         int m = nums1.size()-1;
//         int n = nums2.size()-1;
        
//         while(i<=m && j<=n) {
//             if(nums1[i] >= nums2[j]) {
//                 vec.push_back(nums2[j]);
//                 j++;
//             } else {
//                 vec.push_back(nums1[i]);
//                 i++;
//             }
//         }
        
//         while(i<=m){
//             vec.push_back(nums1[i++]);
//         }
        
//         while(j<=n) {
//             vec.push_back(nums2[j++]);
//         }
        
//         int N = vec.size();
//         double ans = 0;
        
//         if(N&1) {
//             ans = vec[N/2];
//         } else {
//             ans = (vec[N/2]+ vec[(N/2)-1])/2.0;
//         }
        
//         return ans;
        
        if(nums2.size() < nums1.size()) {
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0;
        int high = n1;
        
        
        while(low <= high) {
            
            int cut1 = (low+high)/2;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 ==0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1 == n1? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2? INT_MAX : nums2[cut2];
            
            if(left1 <= right2 && left2 <= right1) {
                
                if((n1 + n2)%2==0) {
                    return (max(left1,left2) + min(right1,right2))/2.0;
                } else {
                    return max(left1,left2);
                }
                
            } else if(left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
            
            
            
            
        }
        
        return 0.0;
        
    }
};