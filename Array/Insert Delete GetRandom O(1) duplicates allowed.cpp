#include<bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int, set<int>> freq;
    RandomizedCollection() {
    }

    bool insert(int val) {
        if(freq[val].empty()){
            int n = arr.size();
            freq[val].insert(n);
            arr.push_back(val);
            return true;
        }
        else{
            int n = arr.size();
            freq[val].insert(n);
            arr.push_back(val);
            return false;
        }
    }

    bool remove(int val) {
        if(freq[val].empty()) return false;
        int idx = *(freq[val].begin());
        int n = arr.size();
        int num = arr.back();
        arr[idx] = num;
            arr.pop_back();
            freq[val].erase(idx);
            freq[num].insert(idx);
            freq[num].erase(n-1);
        return true;
    }

    int getRandom() {
        int n = arr.size();
        return arr[rand()%n];
    }
};