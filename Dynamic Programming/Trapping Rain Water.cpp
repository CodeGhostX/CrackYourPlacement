class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n);
        int maxi = 0;
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi, height[i]);
            right[i] = maxi;
        }
        
        int left = height[0];
        int ans = 0;
        for(int i=1;i<height.size()-1;i++){
            left = max(left, height[i]);
            if(height[i]<left && height[i]<right[i]){
                ans += min(left, right[i]) - height[i];
            }
        }
        return ans;
    }
};
