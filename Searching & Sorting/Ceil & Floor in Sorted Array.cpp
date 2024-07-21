#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int ceil;
	int floor;
	int s = 0;
	int e = n-1;
	while(s<=e){
		int mid = (s+e)/2;
		if(a[mid]==x){
			return {x, x};
		}
		else if(a[mid]<x){
			s = mid+1;
		}
		else e = mid-1;
	}
	floor = e==-1?-1:a[e];
	ceil = s==n?-1:a[s];
	return {floor, ceil};
}