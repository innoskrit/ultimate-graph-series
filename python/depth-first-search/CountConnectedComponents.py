class Solution:

    def build_graph(self, edges, n):
        graph = []

        for i in range(n):
            graph.append(list())

        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        return graph

    def solve(self, node, graph, visited):
        visited[node] = True
        for nbr in graph[node]:
            if not visited[nbr]:
                self.solve(nbr, graph, visited)        

    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = self.build_graph(edges, n)
        visited = [False] * n
        count = 0
        for src in range(n):
            if visited[src] is not True:
                self.solve(src, graph, visited)
                count += 1
        return count