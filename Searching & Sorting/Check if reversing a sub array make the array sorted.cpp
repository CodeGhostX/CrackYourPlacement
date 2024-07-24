#include<bits/stdc++.h>
using namespace std;

void reverse_arr(vector<int> &arr, int i, int j){
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
bool sortArr(int n, vector<int> &arr){
    int i = 0;
    int start = 0;
    int end = 0;
    while(i<n-1){
        if(arr[i]>arr[i+1]) {
            start = i;
            break;
        }
        i++;
    }
    while(i<n-1){
        if(arr[i]<arr[i+1]){
            end = i;
            break;
        }
        i++;
    }
    if(i==n-1) return true;
    reverse_arr(arr, start, end);
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]) return false;
    }
    return true;

}