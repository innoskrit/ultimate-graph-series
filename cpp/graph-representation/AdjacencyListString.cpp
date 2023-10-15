#include <bits/stdc++.h>
using namespace std;

class AdjacencyListString {
public:
    map<string, vector<string>> buildGraph(vector<vector<string>> &edges) {
        map<string, vector<string>> graph;

        for(auto &edge : edges) {
            string src = edge[0];
            string dest = edge[1];

            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }

        return graph;
    }   
};

int main(int argc, char const *argv[]) {
    vector<vector<string>> edges = {
        {"DEL", "BOM"}, 
        {"DEL", "KNP"}, 
        {"DEL", "BLR"}, 
        {"DEL", "HYD"}, 
        {"DEL", "PNQ"},
        {"BLR", "HYD"},
        {"BLR", "PNQ"},
        {"BLR", "BOM"}
    };

    AdjacencyListString adjacencyList;
    
    map<string, vector<string>> graph = adjacencyList.buildGraph(edges);
    for(auto &entry : graph) {
        cout << entry.first << " : ";
        for(auto &nbr : entry.second) {
            cout << nbr << " ";
        }
        cout << endl;
    }
}
