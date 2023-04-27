class Solution {
public:
    vector<int> nextSmallLeft(vector<int> heights) {
        
        vector<int> ans;
        stack<pair<int,int>> s;
        
        for(int i=0; i<heights.size(); i++) {
            
            while(s.size() > 0 && s.top().first>=heights[i]) {
                s.pop();   
            }
            
            if(s.size()==0) {
                ans.push_back(-1);
            } else {
                ans.push_back(s.top().second);
            }
            
            s.push({heights[i],i});
            
        }
       
        return ans;
        
        
    }
    
    vector<int> nextSmalleRight(vector<int> heights) {
        
        vector<int> ans;
        stack<pair<int,int>> s;
        int n = heights.size();
        for(int i=n-1; i>=0; i--) {
            
            while(s.size() > 0 && s.top().first>=heights[i]) {
                s.pop();   
            }
            
            if(s.size()==0) {
                ans.push_back(n);
            } else {
                ans.push_back(s.top().second);
            }
            
            s.push({heights[i],i});
            
            
        }
        reverse(ans.begin(),ans.end());
    
        return ans;
        
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = nextSmallLeft(heights);
        vector<int> right = nextSmalleRight(heights);
        vector<int> width(heights.size(),0);
        for(int i=0; i<left.size(); i++) {
            
            width[i] = right[i]-left[i]-1;
        }
        
        int Area = INT_MIN;
        for(int i=0; i<heights.size(); i++) {
            Area = max(Area,heights[i]*width[i]);
        }
        return Area;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int> vec;
        int maxi = INT_MIN;
        
        for(int i=0; i<matrix[0].size(); i++) {
            vec.push_back(matrix[0][i]-'0');
        }
         
        maxi = largestRectangleArea(vec);
        
        for(int i=1; i<matrix.size(); i++) {
            
            for(int j=0; j<matrix[i].size(); j++) {
                
                if(matrix[i][j]=='0') {
                    vec[j] = 0;
                } else {
                   vec[j] = vec[j]+ (matrix[i][j]-'0');
                }
            }
            maxi = max(maxi,largestRectangleArea(vec));
        }
        
        return maxi;
        
    }
};