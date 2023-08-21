class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        
//         for ( int i = 0 ; i < rows ; i++) {
//             for (int j = i ; j < columns ; j++) {
//                 int temp = matrix[j][i];
//                 matrix[j][i]=matrix[i][j];
//                 matrix[i][j]=temp;
//             }
//      }
        
     
        
//         for( int i = 0 ; i < matrix.size() ; i++) {
//             reverse(matrix[i].begin(),matrix[i].end());
//         }
        
        vector<vector<int>> ans(rows,vector<int>(columns,0));
        for(int i=0; i<rows; i++) {
            for(int j=0; j<rows; j++) {
                
                ans[j][rows-i-1]=matrix[i][j];
                
            }
        }
        matrix = ans;
    }
};