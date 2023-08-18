class Solution {
public:
    string interpret(string command) {
        
        string ans = "";
        
        for(int i=0; i<command.length();) {
            if(command[i]=='G'){
                ans += "G";
                i++;
            } else if(command[i]=='(') { 
                i++;
                string temp = "";
                while(command[i]!=')') {
                    temp += command[i];
                    i++;
                }
                
                if(temp=="") {
                    ans += "o";
                } else {
                    ans+= "al";
                }
                i++;
            }
            
        }
        
        return ans;
        
    }
};