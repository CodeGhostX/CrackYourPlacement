#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "Abhishek Kumar";

    // Solution 1
    // unordered_map<char, int> freq;
    // for(int i=0;i<s.size();i++){
    //     freq[s[i]]++;
    // }
    // for(auto it: freq){
    //     cout<<it.first<<" : "<<it.second<<endl;
    // }

    // Solution 2
    sort(s.begin(), s.end());
    int i = 0;
    while(i<s.size()-1){
        int count = 1;
        while(s[i]==s[i+1]){
            count++;
            i++;
        }
        cout<<s[i]<<" : "<<count;
        i++;
    }
}