#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count_bits(int n){
        int i = 0;
        int ones = 0;
        while(i<32){
            int bit = n&1;
            if(bit) ones++;
            n = n>>1;
            i++;
        }
        return ones;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(count_bits(i));
        }
        return ans;
    }
};