class Solution {
public:
   
    int numOfsetbits(int n) {
    int ans = 0;
      while(n > 0) {
          n = (n)&(n-1);
          ans++;
      }
    
     return ans;

    }

    vector<int> countBits(int n) {

        vector<int> ans;

        for(int i=0; i<=n; i++) {
            int result = numOfsetbits(i);
            ans.push_back(result);
        }

      return ans;
        
    }
};

// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> ret(num+1, 0);
//         for ( int i = 1; i <= num; i++ ) {
//             ret[i] = ret[i/2] + i%2;
//         }
//         return ret;
//     }
// };