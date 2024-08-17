class Solution{
public:

	long long maxProduct(vector<int> arr, int n) {
	    long long ans = LONG_MIN;
	    long long pre = 1, suf = 1, i = 0, j = n-1;
	    while(i<n){
	        pre *= arr[i];
	        suf *= arr[j];
	        ans = max(max(ans, pre) , suf);
	        if(pre==0) pre = 1;
	        if(suf==0) suf = 1;
	        i++, j--;
	    }
	    return ans;
	}
};
