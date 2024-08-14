class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, int>> pq;
        unordered_map<char, int> freq;
        int max_freq = 0;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
            max_freq = max(max_freq, freq[s[i]]);
        }
        if((s.size()&1) && max_freq>=(s.size()/2)+2) return "";      
        if((s.size()%2==0) && max_freq>(s.size()/2)) return "";
        for(auto it: freq){
            pq.push({it.second, it.first});
        }
        string ans = "";
        while(!pq.empty()){
            char ch1 = pq.top().second;
            int f1 = pq.top().first;
            pq.pop();
            char ch2;
            int f2 = 0;
            if(!pq.empty()){
                ch2 = pq.top().second;
                f2 = pq.top().first;
                pq.pop();
            }
            ans += ch1;
            if(f2) ans += ch2;
            f1--;
            f2--;
            if(f1>0) pq.push({f1, ch1});
            if(f2>0) pq.push({f2, ch2});
        }
        return ans;
    }
};
