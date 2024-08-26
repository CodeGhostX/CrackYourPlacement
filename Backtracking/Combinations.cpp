class Solution {
public: 
    void buildAnswer(vector<vector<int>> &ans, int n, int k, vector<int> &temp){
        if(temp.size()==k || n==0) return;
        temp.push_back(n);
        if(temp.size()==k) {
            ans.push_back(temp);
        }
        buildAnswer(ans, n-1, k, temp);
        temp.pop_back();
        buildAnswer(ans, n-1, k, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        buildAnswer(ans, n, k, temp);
        return ans;
    }
};
