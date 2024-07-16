#include<bits/stdc++.h>
using namespace std;

// First Approach

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         for(int i=0;i<nums.size();i++){
//             freq[nums[i]]++;
//         }
//         for(auto it: freq){
//             if(it.second>=2) return it.first;
//         }
//         return -1;
//     }
// };

// Better Approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};