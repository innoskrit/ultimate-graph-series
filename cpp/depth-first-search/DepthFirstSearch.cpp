#include<bits/stdc++.h>
using namespace std;

class DepthFirstSearch {
public:
    vector<vector<int>> buildGraph(vector<vector<int>>& edges, int n) {
        vector<vector<int>> graph(n);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    void solve(int node, vector<int>& dfsAnswer, vector<vector<int>>& graph, vector<bool>& visited) {
        dfsAnswer.push_back(node);
        visited[node] = true;
        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                solve(nbr, dfsAnswer, graph, visited);
            }
        }
    }

    vector<int> depthFirstSearch(vector<vector<int>>& edges, int n, int src) {
        vector<vector<int>> graph = buildGraph(edges, n);
        vector<int> dfsAnswer;
        vector<bool> visited(n, false);
        solve(src, dfsAnswer, graph, visited);
        return dfsAnswer;
    }
};

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 4}, {3, 5}};
    int n = 6;
    int src = 2;
    
    DepthFirstSearch dfs;
    
    vector<int> dfsAnswer = dfs.depthFirstSearch(edges, n, src);
    for (int node : dfsAnswer) {
        cout << node << " ";
    }

    return 0;
}
