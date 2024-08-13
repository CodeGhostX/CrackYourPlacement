class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void DFS(int node, vector<int> adj[], vector<int>& vis, vector<int>&ans){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                DFS(it, adj, vis, ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V, 0);
        DFS(0, adj, vis, ans);
        return ans;
    }
};
