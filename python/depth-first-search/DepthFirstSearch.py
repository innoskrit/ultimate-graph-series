from typing import List

class DepthFirstSearch:

    def __init__(self):
        pass

    def build_graph(self, edges, n):
        graph = []

        for i in range(n):
            graph.append(list())

        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        return graph

    def solve(self, node, dfs_answer, graph, visited):
        dfs_answer.append(node)
        visited[node] = True
        for nbr in graph[node]:
            if not visited[nbr]:
                self.solve(nbr, dfs_answer, graph, visited)

    def depthFirstSearch(self, edges, n, src):
        graph = self.build_graph(edges, n)
        dfs_answer = []
        visited = [False] * n
        self.solve(src, dfs_answer, graph, visited)
        return dfs_answer

if __name__ == "__main__":
    edges = [[0, 1], [0, 2], [1, 2], [1, 3], [1, 4], [2, 5], [3, 4], [3, 5]]
    n = 6
    src = 2
    
    dfs = DepthFirstSearch()
    
    dfs_answer = dfs.depthFirstSearch(edges, n, src)
    for node in dfs_answer:
        print(node, end=" ")
