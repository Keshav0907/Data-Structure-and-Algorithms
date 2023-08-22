class Solution {
public:
    
    int findCount(int &num,long long &success,vector<int> &arr) {
        
        int i=0;
        int j=arr.size()-1;
        
        while(i <= j) {
            int mid = i + (j-i)/2;
            long long mul =(long long)arr[mid]*num;
            if(mul>=success) {
                j = mid-1;
            } else {
                i=mid+1;
            }
        }
        
        return i;
        
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
     
        vector<int> ans;
        int n = potions.size();
        sort(potions.begin(),potions.end());
        
        for(auto num : spells) {
            int count = findCount(num,success,potions);
            ans.push_back(n-count);
        }
        return ans;
    }
};