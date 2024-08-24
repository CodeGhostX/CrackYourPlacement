class Solution {
  public:
    int solve(Node* root, int target, long long curr_sum, unordered_map<long long, int> &freq){
        if(!root) return 0;
        curr_sum += root->data;
        int ans = 0;
        if(curr_sum==target){
            ans++;
        }
        long long rem = curr_sum - target;
        if(freq.find(rem)!=freq.end()) ans += freq[rem];

        freq[curr_sum]++;
        ans += solve(root->left, target, curr_sum, freq);
        ans += solve(root->right, target, curr_sum, freq);
        freq[curr_sum]--;
        return ans;
    }
    int sumK(Node *root, int k) {
        unordered_map<long long, int> freq;
        return solve(root, k, 0LL, freq);
    }
};
