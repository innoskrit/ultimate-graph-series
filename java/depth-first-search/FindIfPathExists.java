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

    private boolean solve(int node, int destination, List<List<Integer>> graph, boolean[] visited) {
        if(node == destination) return true;
        visited[node] = true;

        boolean reached = false;
        for(int nbr : graph.get(node)) {
            if(!visited[nbr]) {
                reached = reached || solve(nbr, destination, graph, visited);
                if(reached) return true;
            }
        }
        return reached;
    }

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        List<List<Integer>> graph = buildGraph(edges, n);
        boolean[] visited = new boolean[n];
        return solve(source, destination, graph, visited);
    }
}