class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int left = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int right = rows * cols - 1;
        // cout << rows << cols;
        
        while(left <= right) {
            
            int mid = left + (right-left)/2;
            int midElement = matrix[mid/cols][mid%cols];
            
            if(midElement==target) {
                return true;
            } else if(midElement > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            
        }
        
        return false;
        
    }
};