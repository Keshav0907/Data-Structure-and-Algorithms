class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();
        if(n%groupSize!=0) return false;
        
        map<int,int> mpp;
        
        for(auto el : hand) {
            mpp[el]++;
        }
        
        for(auto it=mpp.begin();it!=mpp.end(); ) {
        
         if(mpp[it->first] > 0) {
             
             for(int i=0; i<groupSize; i++) {
                 
                 if(mpp[it->first+i] > 0) {
                     mpp[it->first+i]--;
                 } else {
                     return false;
                 }
                 
             }
             
             
         } else {
             it++;
         }
           
        }
        
        return true;
    }
};