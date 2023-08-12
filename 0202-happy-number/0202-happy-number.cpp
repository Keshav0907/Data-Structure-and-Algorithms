class Solution {
public:
    int solve(int num){
        
        int sum =0;
        while(num>0){
        int digit = num % 10;
        sum = sum + digit *digit;
        num = num/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow =n;
        int fast =n;
        do{
            slow = solve(slow);
            fast = solve(solve(fast));
        }while(slow!=fast);
        

        return slow==1;
    }
};