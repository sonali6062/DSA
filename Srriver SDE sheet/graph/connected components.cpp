/*Given a undirected Graph consisting of V vertices numbered from 0 to V-1 and E edges. The ith edge is represented by [ai,bi], 
denoting a edge between vertex ai and bi. We say two vertices u and v belong to a same component if there is a path from u to v 
or v to u. Find the number of connected components in the graph.
A connected component is a subgraph of a graph in which there exists a path between any two vertices, 
and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
Examples:
Input: V=4, edges=[[0,1],[1,2]]
Output: 2
Explanation: Vertices {0,1,2} forms the first component and vertex 3 forms the second component.

Input: V = 7, edges = [[0, 1], [1, 2], [2, 3], [4, 5]]
Output: 3
Explanation:
The edges [0, 1], [1, 2], [2, 3] form a connected component with vertices {0, 1, 2, 3}.
The edge [4, 5] forms another connected component with vertices {4, 5}.
Therefore, the graph has 3 connected components: {0, 1, 2, 3}, {4, 5}, and the isolated vertices {6} (vertices 6 and any other unconnected vertices).
*/
class Solution {
  public:
  void bfs(int node,vector<int>adj[],int vis[]){
    vis[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
      int i=q.front();
      q.pop();
      for(auto it:adj[i]){
        if(!vis[it]){
          vis[it]=1;
          q.push(it);
        }
      }
    }
  }
  public:
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
      int n=edges.size();
      vector<int>adj[V];
      for(int i=0;i<n;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
      }
      int vis[V]={0};
      int cnt=0;
      for(int i=0;i<V;i++){
        if(!vis[i]){
          cnt++;
          bfs(i,adj,vis);
        }
      }
      return cnt;
    }
};

//Time Complexity:O(V+E)
//Space Complexity:O(V)
