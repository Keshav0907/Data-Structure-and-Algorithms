class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        // if(fruits.size()==1) {
        //     return 1;
        // }
        
        int maxFruit = INT_MIN;
        unordered_map<int,int> mpp;
        
        int i=0;
        int j=0;
        
        while(j < fruits.size()) {
            
            mpp[fruits[j]]++;
            
            
            if(mpp.size()<=2) {
                
             maxFruit = max(j-i+1,maxFruit);    
                
            }
            
            while(mpp.size() > 2) {
                
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0) {
                    mpp.erase(fruits[i]);
                }
                i++;
            }
            
            j++;    
        }
        
        return maxFruit;
    
    }
};