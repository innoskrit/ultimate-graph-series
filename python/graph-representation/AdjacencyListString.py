class AdjacencyListString:

    def build_graph(self, edges):
        graph = dict()

        for edge in edges:
            src = edge[0]
            dest = edge[1]
            
            if src not in graph:
                graph[src] = list()
            graph[src].append(dest)
            
            if dest not in graph:
                graph[dest] = list()
            graph[dest].append(src)

        return graph

if __name__ == '__main__':
    edges = [
        ["DEL", "BOM"], 
        ["DEL", "KNP"], 
        ["DEL", "BLR"], 
        ["DEL", "HYD"], 
        ["DEL", "PNQ"],
        ["BLR", "HYD"],
        ["BLR", "PNQ"],
        ["BLR", "BOM"]
    ]

    adjacencyList = AdjacencyListString()
    
    graph = adjacencyList.build_graph(edges)
    for (key, value) in graph.items():
        print(key, end = " : ")
        for nbr in value:
            print(nbr, end = " ")
        print()