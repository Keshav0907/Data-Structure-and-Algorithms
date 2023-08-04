class Solution {
public :
    
vector<int> generateRow(int row) {
    
    vector<int> ans;
    ans.push_back(1);
    int result = 1;
    for(int col=1; col<row; col++) {
        
        result = result * (row-col);
        result = result/col;
        ans.push_back(result);
        
    }

    
    return ans;
    
}
    
    
vector<vector<int>> generate(int numRows) {
  
    vector<vector<int>> result;
        
     for(int i=1; i<=numRows; i++) {
         result.push_back(generateRow(i));
     }
    
	
    return result;    
        
        
 }
};