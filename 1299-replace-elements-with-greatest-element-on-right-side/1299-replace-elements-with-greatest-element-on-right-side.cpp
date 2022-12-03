class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
	{
        stack<int> hello ;  // Initialize a stack
        vector<int> ans (1,-1) ; // base condition , -1 should be present in array at last position
        
        hello.push(arr[arr.size()-1]) ; // push last element in stack because it is necessary 
        for (int i=arr.size()-2; i>=0 ; i--) // traverse it from back
        {
            ans.push_back(hello.top()) ;
            
            if (hello.top()<arr[i]) // check maximum element 
                hello.push(arr[i]) ;  // if found then push it into stack
        }
        
        reverse(ans.begin(),ans.end()) ; // reverse your answer array 
        return ans ; // here is your solution
        
    }
};