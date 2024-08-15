class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int, int> freq;
        int maxi = 0;
        long long total = 0;
        for(int i=0;i<n;i++){
            total += arr[i];
            if(total==0){
                maxi = max(i+1, maxi);
            }
            else if(freq.find(total)==freq.end()){
                freq[total] = i;
            }
            else {
                int diff = i-freq[total];
                maxi = max(maxi, diff);
            }
        }
        return maxi;
    }
};
