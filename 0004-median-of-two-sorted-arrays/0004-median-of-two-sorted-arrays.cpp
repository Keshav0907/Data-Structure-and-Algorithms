class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> vec;
        
        int i=0;
        int j=0;
        int m = nums1.size()-1;
        int n = nums2.size()-1;
        
        while(i<=m && j<=n) {
            if(nums1[i] >= nums2[j]) {
                vec.push_back(nums2[j]);
                j++;
            } else {
                vec.push_back(nums1[i]);
                i++;
            }
        }
        
        while(i<=m){
            vec.push_back(nums1[i++]);
        }
        
        while(j<=n) {
            vec.push_back(nums2[j++]);
        }
        
        int N = vec.size();
        double ans = 0;
        
        if(N&1) {
            ans = vec[N/2];
        } else {
            ans = (vec[N/2]+ vec[(N/2)-1])/2.0;
        }
        
        return ans;
        
        
    }
};