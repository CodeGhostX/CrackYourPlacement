class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(int node, vector<int> adj[], vector<int>& vis, int parent){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(vis[it] && it!=parent) return true;
            if(!vis[it]){
                if(checkCycle(it, adj, vis, node)) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i, adj, vis, -1)) return true;
            }
        }
        return false;
    }
};
