
class Solution {
public:
void dfs(vector<vector<int>>& image, int row, int col, int color,vector<vector<int>> &vis,int k){

   int n= image.size();
   int m= image[0].size();
   if(row<0 || col<0 || row>=n || col>=m || image[row][col]!=k || vis[row][col]==1) return ;
  
  image[row][col]= color;
  vis[row][col]=1;
   
   dfs(image,row-1,col,color,vis,k);
   dfs(image,row+1,col,color,vis,k);
   dfs(image,row,col-1,color,vis,k);
   dfs(image,row,col+1,color,vis,k);



}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int n= image.size();
       int m= image[0].size();
       vector<vector<int>> vis(n,vector<int>(m,0));
       
       int k= image[sr][sc];
       dfs(image,sr,sc,color,vis,k);

        return image;
        
    }
};