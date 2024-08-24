class Solution {
public:
    int solve(TreeNode* root, int target, long long curr_sum, unordered_map<long long, int> &freq){
        if(!root) return 0;
        curr_sum += root->val;
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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> freq;
        return solve(root, targetSum, 0LL, freq);
    }
};
