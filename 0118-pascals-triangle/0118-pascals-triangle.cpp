class Solution {
public:
//     vector<vector<int>> generate(int numRows) {
        
//         vector<vector<int>> r(numRows);
        
//         for(int i=0; i<numRows; i++) {
//             r[i].resize(i+1);
//             r[i][0] = r[i][i] = 1;
            
//             for(int j=1; j<i; j++) {
//                 r[i][j] = r[i-1][j-1]+r[i-1][j];
//             }
            
//         }
        
//         return r;
//     }
    
    vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ret;
	for (int i = 0; i < numRows; i++) {
		vector<int> row(i + 1, 1);
		for (int j = 1; j < i; j++) {
			row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
		}
		ret.push_back(row);
	}
	return ret;
}
};