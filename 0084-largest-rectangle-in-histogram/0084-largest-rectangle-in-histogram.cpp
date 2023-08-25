class Solution {
public:
     
    vector<int> nextSmallLeft(vector<int> &heights) {
        
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=0; i<heights.size(); i++) {
            
            if(st.size()==0) {
                ans.push_back(-1);
            } else {
                
                if(st.top().first < heights[i]) {
                    ans.push_back(st.top().second);
                } else {
                    
                    while(st.size() > 0 && st.top().first >= heights[i]) {
                        
                        st.pop();
                        
                    }
                    
                    if(st.size()==0) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(st.top().second);
                    }
                    
                }
                
                
            }
            
            
           st.push({heights[i],i}); 
            
        }
         return ans;
    }
    
        vector<int> nextSmallRight(vector<int> &heights) {
        
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=heights.size()-1; i>=0; i--) {
            
            if(st.size()==0) {
                ans.push_back(heights.size());
            } else {
                
                if(st.top().first < heights[i]) {
                    ans.push_back(st.top().second);
                } else {
                    
                    while(st.size() > 0 && st.top().first >= heights[i]) {
                        
                        st.pop();
                        
                    }
                    
                    if(st.size()==0) {
                        ans.push_back(heights.size());
                    } else {
                        ans.push_back(st.top().second);
                    }
                    
                }
                
                
            }
            
            
           st.push({heights[i],i}); 
            
        }
            
            reverse(ans.begin(),ans.end());
            return ans;
         
    }
    
    
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = nextSmallLeft(heights);
        vector<int> right = nextSmallRight(heights);
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
};