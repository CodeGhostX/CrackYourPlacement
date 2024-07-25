#include<bits/stdc++.h>
using namespace std;


// Basic Approach O(n(log(n)))
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        sort(arr, arr+n);
        int i = 0;
        int a = 1;
        while(i<n){
            if(arr[i]==1){
                a = 1;
                while(i<n){
                    if(arr[i]!=a && arr[i]!=arr[i-1]){
                        return a;
                    }
                    if(arr[i]!=arr[i-1]) a++;
                    i++;
                }
            }
            i++;
        }
        return a;
    }
};

// Optimized Approach
class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        bool oneFlag = false;
        int n = arr.size();
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1) oneFlag = true;
            else if(arr[i]>n || arr[i]<=0){
                arr[i] = 1;
            }
        }
        if(oneFlag==false) return 1;
        for(int i=0;i<n;i++){
            int val = abs(arr[i]);
            if(arr[val-1]>0) arr[val-1] = -1*arr[val-1];
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0) return i+1;
        }
        return n+1;
    }
};