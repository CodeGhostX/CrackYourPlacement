#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find minimum number of pages.
    int numberOfStudents(int arr[], int max_pages, int n){
        int i = 0;
        int curr = 0;
        int count = 0;
        while(i<n){
            if(curr + arr[i]<=max_pages) {
                curr += arr[i];
                i++;
            }
            else{
                count++;
                curr = 0;
            }
        }
        return count+1;
    }
    long long findPages(int n, int arr[], int m) {
        if(m>n) return -1;
        long long start = *max_element(arr, arr+n);
        long long end = 0;
        for(int i=0;i<n;i++){
            end += arr[i];
        }
        while(end>=start){
            long long mid = (start+end)/2;
            if(numberOfStudents(arr, mid, n)>m) start = mid+1; 
            else if(numberOfStudents(arr, mid, n)<=m) end = mid-1;
        }
        return start;
    }
};