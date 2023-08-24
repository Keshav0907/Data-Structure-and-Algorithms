class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int l = 0;
        int r = 1;
        string prev = "";
        int res = 1;
        
        while(r < arr.size()) {
            
            if(arr[r-1] > arr[r] && prev!=">"){
                res = max(r-l+1,res);
                prev = ">";
                r++;
            } else if(arr[r-1] < arr[r] && prev!="<") {
                res = max(r-l+1,res);
                prev = "<";
                r++;
            } else {
                if(arr[r]==arr[r-1]) {
                    r = r+1;
                }
                l = r-1;
                prev = "";
            }
            
        }
        return res;
    }
};

