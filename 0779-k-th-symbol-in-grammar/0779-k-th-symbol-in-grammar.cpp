class Solution {
public:
    
//     void helper(int n,int i ,string &s) {
        
//         if(i == n) {
//             return ;
//         }
        
//         s.replace('0','01');
//         s.replace('1','10');
//         helper(n,i+1,s);
        
//     }
    int kthGrammar(int n, int k) {

        if(n==1 && k==1) {
            return 0;
        }
        
        
        int mid = pow(2,n-1)/2;;
        
        if(k <= mid) {
            return kthGrammar(n-1,k);
        } 
        
        return !kthGrammar(n,k-mid);
        
        
    }
};