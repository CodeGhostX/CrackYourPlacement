class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int position = startFuel;
        int n = stations.size();
        int i = 0;
        while(i<n){
            if(position>=target) return i-pq.size();
            else if(stations[i][0]<=position){
                pq.push(stations[i][1]);
                i++;
            }
            else if(!pq.empty()){
                int dist = pq.top();
                pq.pop();
                position += dist;
            }
            else if(pq.empty() && position<stations[i][0]) return -1;
        }
        while(position<target && !pq.empty()){
            position += pq.top();
            pq.pop();
        }
        if(position<target) return -1;
        return n-pq.size();
    }
};
