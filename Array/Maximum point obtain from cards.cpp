#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int firstK = 0;
        for(int i=0;i<k;i++){
            firstK += cardPoints[i];
        }
        int i = k-1;
        int s = 1;
        int ans = firstK;
        int curr = firstK;
        for(int j=0;j<k;j++){
            curr = curr + cardPoints[n-s] - cardPoints[i];
            s++;
            i--;
            ans = max(ans, curr);
        }
        return ans;
    }
};