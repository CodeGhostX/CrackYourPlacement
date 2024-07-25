#include<bits/stdc++.h>
using namespace std;

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