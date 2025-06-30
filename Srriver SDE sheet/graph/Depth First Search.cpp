class Solution {
private:
    void dfsUtil(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ls) {
        vis[node] = 1;
        ls.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsUtil(it, adj, vis, ls);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ls;
        dfsUtil(0, adj, vis, ls);  // Start DFS from node 0
        return ls;
    }
};
//TC=O(N)+2*e
//SC=O(N)
