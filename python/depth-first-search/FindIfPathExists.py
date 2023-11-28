class Solution:

    def build_graph(self, edges, n):
        graph = []

        for i in range(n):
            graph.append(list())

        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        return graph

    def solve(self, node, destination, graph, visited):
        if node == destination:
            return True

        visited[node] = True

        reached = False
        for nbr in graph[node]:
            if not visited[nbr]:
                reached = reached or self.solve(nbr, destination, graph, visited)
                if reached:
                    return True

        return reached

    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = self.build_graph(edges, n)
        visited = [False] * n
        return self.solve(source, destination, graph, visited)
