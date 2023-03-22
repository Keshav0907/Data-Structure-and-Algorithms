class Solution {
public:
    
   bool search(int i,int j,vector<vector<char>>& board, string &word,int n,int m,int k) {
       
       if(k==word.size()) {
           return true;
       }
       
       if(i<0 || i==n || j<0 || j==m || board[i][j]!=word[k]) {
           return false;
       }
       
       char ch = board[i][j];
       board[i][j] = '#';
       bool op1 = search(i+1,j,board,word,n,m,k+1);
       bool op2= search(i-1,j,board,word,n,m,k+1);
       bool op3 = search(i,j+1,board,word,n,m,k+1);
       bool op4 = search(i,j-1,board,word,n,m,k+1);
       board[i][j] = ch;
       return op1 || op2 || op3 || op4;
   }
    
    bool exist(vector<vector<char>>& board, string word) {
       
       int n = board.size();
       int m = board[0].size();
        
       for(int i=0; i<n; i++) {
           for(int j=0; j<m; j++) {
               
               if(board[i][j]==word[0]) {
                   if(search(i,j,board,word,n,m,0)) {
                       return true;
                   }
               }
               
           }
       }
        
        return false;
        
    }
};