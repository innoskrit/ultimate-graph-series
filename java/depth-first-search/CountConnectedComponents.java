import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<List<Integer>> buildGraph(int[][] edges, int n) {
        List<List<Integer>> graph = new ArrayList<>();
        
        for(int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for(int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }

        return graph;

    }

    private void solve(int node, List<List<Integer>> graph, boolean[] visited) {
        visited[node] = true;
        for(int nbr : graph.get(node)) {
            if(!visited[nbr]) {
                solve(nbr, graph, visited);
            }
        }
    }

    public int countComponents(int n, int[][] edges) {
        List<List<Integer>> graph = buildGraph(edges, n);
        boolean[] visited = new boolean[n];
        int count = 0;
        for(int src = 0; src < n; src++) {
            if(!visited[src]) {
                solve(src, graph, visited);
                count += 1;
            }
        }
        return count;
    }
}