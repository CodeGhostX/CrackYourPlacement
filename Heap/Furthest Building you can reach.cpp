class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladder) {
        int i = 0;
        int n = heights.size();
        priority_queue<int> pq;
        while(i<n){
            int diff = INT_MAX;
            if(i+1<n){
                diff = heights[i+1] - heights[i];
            }
            if(diff<=0){
                i++;
            }
            else{
                // itte hai
                if(bricks>=diff){
                    bricks -= diff;
                    pq.push(diff);
                    i++;
                }
                // itte kahatam
                else if(bricks<diff && ladder>0 && !pq.empty() && pq.top()>=diff){
                    bricks += pq.top();
                    pq.pop();
                    ladder--;
                }
                else if(ladder){
                    ladder--;
                    i++;
                }
                else if(bricks<diff && ladder==0){
                    break;
                }
            }
        }
        if(i==n) i--;
        return i;
    }
};
