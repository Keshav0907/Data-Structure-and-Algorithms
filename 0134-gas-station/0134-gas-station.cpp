class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0;
        int costSum = 0;
        int currentFuel = 0;
        
        for(int i=0; i<gas.size(); i++) {
            gasSum += gas[i];
            costSum +=cost[i];
        }

        if(gasSum < costSum) {
            return -1;
        }
        
        int start = 0;
        
        for(int i=0; i<gas.size(); i++) {
            
            currentFuel += (gas[i]-cost[i]);
            if(currentFuel < 0) {
                start = i+1;
                currentFuel =0;
            }
        }

        return start;
    }
};