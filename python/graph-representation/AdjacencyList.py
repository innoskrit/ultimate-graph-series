class AdjacencyList:

    def build_graph(self, edges, n):
        graph = []

        for i in range(n):
            graph.append(list())

        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        return graph

if __name__ == '__main__':
    edges = [[0, 1], [0, 2], [1, 2], [1, 3], [1, 4], [2, 5], [3, 4], [3, 5]]
    n = 6

    adjacencyList = AdjacencyList()
    
    graph = adjacencyList.build_graph(edges, n)
    for i in range(n):
        print(i, end = " : ")
        for nbr in graph[i]:
            print(nbr, end = " ")
        print()