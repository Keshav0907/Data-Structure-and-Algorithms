class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
};

        // s.push(nums2[nums2.size()-1]);
        
//         for(int i=nums2.size()-1; i>=0; i--) {
//             if(s.find(nums2[i])!=s.end()) {
                
//                 if(!st.empty()) {
                    
//                     if(st.top() > nums2[i]) {
//                         ans.push_back(st.top());
//                     } else {
//                         ans.push_back(-1);
//                         st.push(nums2[i]);
//                     }
                    
                    
//                 } else {
//                     ans.push_back(-1);
                
//                 }
                
//             }
//                 st.push(nums2[i]);
//         }
        
        // reverse(ans.begin(),ans.end());