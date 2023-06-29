class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int n = a.size(), m = b.size();
        int i = n-1, j = m-1;
        while(i>=0 || j>=0) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            res.insert(res.begin(), char(sum%2 + '0'));
            //convert sum from int to char and then insert into front of result
        }
        if(carry) //if carry still equal to 1
            res.insert(res.begin(), '1');
        return res;
    }
};