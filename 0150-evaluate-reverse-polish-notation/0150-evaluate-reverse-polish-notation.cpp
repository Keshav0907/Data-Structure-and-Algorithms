class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        for(auto ch : tokens) {
            
            if(ch=="+"){
                int ele1 = s.top();
                s.pop();
                int ele2 = s.top();
                s.pop();
                s.push(ele1+ele2);
            } else if(ch=="-") {
                int ele1 = s.top();
                s.pop();
                int ele2 = s.top();
                s.pop();
                s.push(ele2-ele1);
            } else if(ch=="*") {
                int ele1 = s.top();
                s.pop();
                int ele2 = s.top();
                s.pop();
                s.push(ele1*ele2);
            } else if(ch=="/") {
                int ele1 = s.top();
                s.pop();
                int ele2 = s.top();
                s.pop();
                s.push(ele2/ele1);
            } else {
                s.push(stoi(ch));
            }
            
        }
        
        return s.top();
        
    }
};