class Solution {
public:

    vector<vector<int>> buildGraph(vector<vector<int>>& edges, int n) {
        vector<vector<int>> graph(n);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    bool solve(int node, int destination, vector<vector<int>>& graph, vector<bool>& visited) {
        if(node == destination) {
            return true;
        }

        visited[node] = true;

        bool reached = false;
        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                reached = reached || solve(nbr, destination, graph, visited);
                if(reached) return true;
            }
        }

        return reached;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph = buildGraph(edges, n);
        vector<bool> visited(n, false);
        return solve(source, destination, graph, visited);
    }

};