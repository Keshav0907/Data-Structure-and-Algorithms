class Solution {
public:
    
//     bool canPlace(vector<vector<string>> str,int i,int j,int n) {
        
//         for(int k=0; k<i; k++) {
//             if(str[i][j]=='Q') {
//                 return false;
//             }
//         }
        
//         int row = i-1;
//         int col = j;
//         while(row >=0 && col>=0) {
//             if(s[i][j]=='Q') {
//                 return false;
//             }
//             row--;
//             col--;
//         }
        
//         int row = i;
//         int col = j;
        
//         while(row>=0 && col<n) {
//             if(s[i][j]=='Q') {
//                return false; 
//             }
//             row--;
//             col++;
//         }
        
//         return true;
        
//     }
    
    
//     void helper(vector<vector<int>> &str,int i,int n) {
        
//        if(i==n) {
//          return;  
//        }
       
//         for(int j=0; j<n; j++) {
//             str[i][j] = 'Q';
//             if(canPlace(str,i,j,n)) {
//                 helper(str,i+1,n);
//             }
//             str[i][j] = '.';
//         }
        
//     }
    
//     vector<vector<string>> solveNQueens(int n) {
        
//         vector<vector<string>> s(n,n);
//         for(int i=0; i< n; i++) {
//             for(int j=0; j<n; j++) {
//                 s[i][j]='.';
//             }
//         }
        
//         helper(s,0,n);
        
//     }
    
      bool isSafe1(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

     public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }
    
      vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      solve(0, board, ans, n);
      return ans;
    }

};