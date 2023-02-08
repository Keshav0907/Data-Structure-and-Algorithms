class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());
        int numOfboats = 0;

         int i = 0;
         int j = people.size()-1;
         
       while (i <= j) {
            numOfboats++;
            if (people[i] + people[j] <= limit)
                i++;
            j--;
        }
        
        
        
        
        return numOfboats;
        
        
    }
};