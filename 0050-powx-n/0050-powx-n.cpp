// class Solution {
// public:
    
//     double helper(double x, int n) {
        
//         double subProb = myPow(x,n/2);
//         double subProbsq = subProb*subProb;
            
//         if(n%2==0) {
//                 return subProbsq;
//          } 
     
//          return x*subProbsq;
                 
//     }
    
//     double myPow(double x, int n) {
        
//         // double multiplier = 1;
//         // if(x < 0 && n%2==1) {
//         //     cout << "hello";
//         //     multiplier = -1;
//         // }    
//         if(n==0) {
//             return 1;
//         }
//         int result;
//         if(n > 0) {
           
//           if(x<0 && n%2==1) {
//              return -1*helper(-x,n);  
//           } else {
//               return helper(x,n);
//           }
         
            
//         } 
            
//         if(x<0 && n%2==1) {
//             return -1.00/helper(-x,-n);
//         }    
            
//         return 1.00/helper(x,-n);    
        
        
//     }
// };

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
        return 1;
        if(n==1)
        return x;
        double ans = myPow(x,n/2);
        if(n%2==0){
            return ans*ans;
        }
        else if(n%2==1){
            return x*ans*ans;
        }
        else{
            return 1/myPow(x,-n);
        }

    }
};