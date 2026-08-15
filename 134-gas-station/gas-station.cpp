class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int costSum = 0;
        int gasSum = 0;
        for(int i=0; i<n; i++){
            costSum += cost[i];
            gasSum += gas[i];
        }

        if(gasSum < costSum) return -1;

        int tank = 0;
        int startPoint = 0;
        for(int i=0; i<n; i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                startPoint = i+1;
                tank = 0;
            }
        }
        return startPoint;
    }
};