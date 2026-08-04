class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for(int neighbor: adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // build adjacency list
        vector<vector<int>> adj(n);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int componentCount = 0;

        for(int node = 0; node < n; node++) {
            if(!visited[node]) {
                componentCount++;
                dfs(node, adj, visited); // visit all nodes in this component
            }
        }

        return componentCount;
    }
};
