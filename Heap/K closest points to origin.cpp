class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, int>> arr;
        for(int i=0;i<points.size();i++){
            double dist = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            arr.push_back({dist, i});
        }
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            int idx = arr[i].second;
            ans.push_back(points[idx]);
        }
        return ans;
    }
};
