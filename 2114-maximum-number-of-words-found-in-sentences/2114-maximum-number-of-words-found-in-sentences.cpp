class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n;
        int max=0;
        for(string s:sentences){
            n=count(s);
            if(n>max){
                max=n;
            }
        }
        return max;
    }
    private:
        int count(string s){
            int n=0;
            for(char c:s){
                if(c==' '){
                    n++;
                }
            }
            return n+1;
        }
};