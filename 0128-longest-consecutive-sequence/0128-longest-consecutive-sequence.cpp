class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
       if(nums.size()==0) {
           return 0;
       }        
       unordered_set<int> s;
       
        for(auto x : nums) {
            s.insert(x);
        }
        
        int longest = 0;
        
        for(auto num : nums) {
            
            if(s.find(num-1)==s.end()) {
                
                int currentnum = num;
                int currentStreak = 1;
                
                while(s.find(currentnum+1)!=s.end()) {
                    currentnum +=1;
                    currentStreak +=1;
                }
                
                longest = max(currentStreak,longest);
                  
            }
            
            
        }

        
        return longest;

        
    }
};