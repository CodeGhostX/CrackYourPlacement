class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> freq;
        for(int i=0;i<s.size();i++){
            if(freq.size()==0 || freq.back().first!=s[i]){
                freq.push_back({s[i], 1});
            }
            else{
                freq.back().second += 1;
                if(freq.back().second==k) freq.pop_back();
            }
        }
        string ans;
        for(int i=0;i<freq.size();i++){
            int a = freq[i].second;
            char ch = freq[i].first;
            for(int j=0;j<a;j++){
                ans += ch;
            }
        }
        return ans;
    }
};
