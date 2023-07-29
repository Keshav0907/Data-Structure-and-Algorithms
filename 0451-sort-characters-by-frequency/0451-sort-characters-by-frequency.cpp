


class Solution {
public:
    
    static bool comp(pair<char,int> a, pair<char,int> b) {

       return a.second > b.second;

    }
    
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        mpp.clear();
        for(int i=0; i<s.length(); i++) {
            mpp[s[i]]++;
        }
        
        vector<pair<char,int>> vec;
        
        for(auto it: mpp) {
            vec.push_back({it.first,it.second});
        }
        
        sort(vec.begin(),vec.end(),comp);
        string ans = "";
        
        for(int i=0; i<vec.size(); i++) {
        
            while(vec[i].second--) {
            
                ans += vec[i].first;
            
            }
         
           
        }
        
        return ans;
    }
};