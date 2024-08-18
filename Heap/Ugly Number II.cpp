class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> ans;
        int main;
        int count = 0;
        ans.insert(1);
        while(count<n){
            int num = *ans.begin();
            main = num;
            count++;
            ans.insert(1ll*num*2);
            ans.insert(1ll*num*3);
            ans.insert(1ll*num*5);
            ans.erase(num);
        }
        return main;
    }
};
