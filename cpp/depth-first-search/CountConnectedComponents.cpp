#include<bits/stdc++.h>
using namespace std;

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

    void solve(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                solve(nbr, graph, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph = buildGraph(edges, n);
        vector<bool> visited(n, false);
        int count = 0;
        for(int src = 0; src < n; src++) {
            if(!visited[src]) {
                solve(src, graph, visited);
                count += 1;
            }
        }
        return count;
    }
};