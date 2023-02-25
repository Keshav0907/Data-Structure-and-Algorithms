class Solution {
public:
    
    bool canRemove(string s,string p,vector<int> &rm,int k) {
        for(int i=0; i<k; i++) {
            s[rm[i]] = '?';
        }
        
        int n1 = s.length();
        int n2 = p.length();
        
        int i=0;
        int j=0;
        
        while(i<n1 && j<n2) {
            if(s[i]==p[j]) {
                j++;;
            }
            
            i++;
        }
        
        return j==n2;
    }
    
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        int ans = 0;
        int left = 0;
        int right = removable.size();
        
        while(left <= right) {
            
            int mid = left + (right-left)/2;
            if(canRemove(s,p,removable,mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            
        }
        
        return ans;
        
    }
};