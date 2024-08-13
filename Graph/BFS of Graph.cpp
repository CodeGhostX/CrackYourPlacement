class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vector<int> vis(V, 0);
        vis[0] = 1;
        while(!q.empty()){
            int f = q.front();
            ans.push_back(f);
            q.pop();
            for(auto it: adj[f]){
                if(vis[it]==0){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
