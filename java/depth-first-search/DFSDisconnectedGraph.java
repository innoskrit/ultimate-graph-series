import java.util.ArrayList;
import java.util.List;

class DFSDisconnectedGraph {

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

    private void solve(int node, List<Integer> dfsAnswer, List<List<Integer>> graph, boolean[] visited) {
        dfsAnswer.add(node);
        visited[node] = true;
        for(int nbr : graph.get(node)) {
            if(!visited[nbr]) {
                solve(nbr, dfsAnswer, graph, visited);
            }
        }
    }

    private List<Integer> depthFirstSearch(int[][] edges, int n) {
        List<List<Integer>> graph = buildGraph(edges, n);
        List<Integer> dfsAnswer = new ArrayList<>();
        boolean[] visited = new boolean[n];
        for(int src = 0; src < n; src++) {
            if(!visited[src]) {
                solve(src, dfsAnswer, graph, visited);
            }
        }
        return dfsAnswer;
        
    }

    public static void main(String[] args) {
        int[][] edges = new int[][]{{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 4}, {3, 5}, {6, 7}, {7, 8}, {9, 10}};
        int n = 11;
        
        DFSDisconnectedGraph dfs = new DFSDisconnectedGraph();
        
        List<Integer> dfsAnswer = dfs.depthFirstSearch(edges, n);
        for(int node : dfsAnswer) {
            System.out.print(node + " ");
        }
    }
}