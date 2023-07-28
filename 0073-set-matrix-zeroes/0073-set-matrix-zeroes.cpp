class Solution {
public:
    
    void setRow(int row,int n,vector<vector<int>> &matrix) {
        for(int i=0; i<n; i++) {
            matrix[row][i]=0;
        }     
    }
    
    void setCol(int col,int m,vector<vector<int>> &matrix) { 
        for(int j=0; j<m; j++) {
            matrix[j][col]=0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
//         unordered_set<int> st;
//         unordered_set<int> st2;
        
//         for(int i=0; i<m; i++) {
//             for(int j=0; j<n; j++) {
                
//                 if(matrix[i][j]==0) {
//                     st.insert(i);
//                     st2.insert(j);
//                 }
                
//             }
//         }
        
//         for(auto it: st) {
//             setRow(it,n,matrix);
//         }
        
//         for(auto it: st2) {
//             setCol(it,m,matrix);
//         }
        
        int col0 = 1;
        for(int i=0; i<m; i++) {
           for(int j=0; j<n; j++) {
               if(matrix[i][j]==0) {
                    matrix[i][0]=0;            
                    if(j!=0) {
                        matrix[0][j]=0;
                    } else {
                        col0=0;
                    }  
                }     
            }
        }
        
        for(int i=1; i<m; i++) {
            
            for(int j=1; j<n; j++) {
                
                if(matrix[i][0]==0 || matrix[0][j]==0) {
                    matrix[i][j]=0;
                }
                
                
            }
            
        }
        
        if(matrix[0][0]==0) {
            for(int j=0; j<n; j++) {
                matrix[0][j]=0;
            }
        
        }
        
        if(col0==0) {
            for(int i=0; i<m; i++) {
                matrix[i][0]=0;
            }
        }
        
    }
};