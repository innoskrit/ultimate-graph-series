import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class AdjacencyListString {

    public Map<String, List<String>> buildGraph(String[][] edges) {
        Map<String, List<String>> graph = new HashMap<>();

        for(String[] edge : edges) {
            String src = edge[0];
            String dest = edge[1];
            
            if(!graph.containsKey(src)) {
                graph.put(src, new ArrayList<>());
            }
            graph.get(src).add(dest);

            if(!graph.containsKey(dest)) {
                graph.put(dest, new ArrayList<>());
            }
            graph.get(dest).add(src);
            
        }

        return graph;
    }

    public static void main(String[] args) {
        String[][] edges = new String[][]{
            {"DEL", "BOM"}, 
            {"DEL", "KNP"}, 
            {"DEL", "BLR"}, 
            {"DEL", "HYD"}, 
            {"DEL", "PNQ"},
            {"BLR", "HYD"},
            {"BLR", "PNQ"},
            {"BLR", "BOM"}
        };
        
        AdjacencyListString adjacencyList = new AdjacencyListString();
        
        Map<String, List<String>> graph = adjacencyList.buildGraph(edges);
        for(Map.Entry<String, List<String>> entry : graph.entrySet()) {
            System.out.print(entry.getKey() + " : ");
            for(String nbr : entry.getValue()) {
                System.out.print(nbr + " ");
            }
            System.out.println();
        }
    }
}