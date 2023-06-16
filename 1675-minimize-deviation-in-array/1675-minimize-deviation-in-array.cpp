class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int> maxH;
        
        int diff = INT_MAX;
        int mini = INT_MAX;
        
        for(auto x : nums) {
            if(x% 2!= 0) x*=2;
            mini = min(x,mini);
            maxH.push(x);
        }
        
        while(maxH.top()%2==0) {
            int ele = maxH.top();
            maxH.pop();
            diff = min(diff,ele - mini);
            mini = min(mini,ele/2);
            maxH.push(ele/2);
        }
        
        return min(diff,maxH.top()-mini);
        
    }
};

// class Solution {
// public:
//     int minimumDeviation(vector<int>& nums) {
//         priority_queue<int> maxpq; //max heap
//         int m = INT_MAX, diff = INT_MAX;
//         for(auto i : nums){
//             if(i%2 != 0) i*=2;
//             m = min(m, i);
//             maxpq.push(i);
//         }
        
//         while(maxpq.top()%2 == 0) {
//             int mx = maxpq.top();
//             maxpq.pop();
//             diff = min(diff, mx - m);
//             m = min(m, mx/2);
//             maxpq.push(mx/2);
//         }
    
//         return min(diff, maxpq.top() - m);
//     }
// };