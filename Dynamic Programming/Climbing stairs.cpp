#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int second_last = 1;
        int last = 2;
        if(n==2) return last;
        if(n==1) return second_last;
        for(int i=3;i<=n;i++){
            int curr = last+second_last;
            second_last = last;
            last = curr;
        }
        return last;
    }
};