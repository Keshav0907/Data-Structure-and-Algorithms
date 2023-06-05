class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> charCount(26,0);
        
        for(int i=0; i<tasks.size(); i++) {
            charCount[tasks[i]-'A']++;
        }
        
        sort(charCount.begin(),charCount.end());
        int maxValue = charCount[25]-1;
        int idleSlot = (maxValue)*n;
        
        for(int i=24; i>=0; i--) {
            idleSlot -= min(maxValue,charCount[i]);
        }
        
        return idleSlot > 0 ? tasks.size()+idleSlot : tasks.size();
    }
};