class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        int carry = 0;
        vector<int> ans;
        int i = n-1;
        bool first = true;
        int sum;
        while(i>=0 || carry) {
            if(first)  {
                sum = 1;
                first = false;
            } else { 
                sum = 0;
            }
            if(i>=0) sum += digits[i];
            sum = sum + carry;
            ans.push_back(sum%10);
            carry = sum/10;
            i--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};