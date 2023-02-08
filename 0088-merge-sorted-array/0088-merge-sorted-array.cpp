// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
//         vector<int> aux;
        
//         int i=0;
//         int j=0;
        
//         while(i < m && j < n) {
//             if(nums1[i] <= nums2[j]) {
//                 aux.push_back(nums1[i]);
//                 i++;
//             } else {
//                 aux.push_back(nums2[j]);
//                 j++;
//             }
//         }
        
//         while(i < m) {
//             aux.push_back(nums1[i++]);
//         }
        
//         while(j < n) {
//             aux.push_back(nums2[j++]);
//         }
        
    
//         for(int i=0; i<aux.size(); i++) {
//             nums1[i] = aux[i];
//         }
        
//     }
// };

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=m-1 , j=n-1 ;
        while(i>=0 && j>=0 ){
            if(nums1[i]>=nums2[j]){
                nums1[i+j+1]=nums1[i] ;
                i-- ;
                }else{
                    nums1[i+j+1]=nums2[j];
                    j-- ;
                }
        }
        while(j>=0){
                    nums1[j]=nums2[j];
                    j-- ;
        }
        
    }
};