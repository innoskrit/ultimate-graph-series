from collections import deque

class BreadthFirstSearch:

    def build_graph(self, edges, n):
        graph = []

        for i in range(n):
            graph.append(list())

        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        return graph
    
    def breadth_first_search(self, edges, n, src):
        graph = self.build_graph(edges, n)

        queue = deque()
        visited = [False] * n
        bfs_answer = []

        queue.append(src)
        visited[src] = True

        while queue:
            curr = queue.popleft()
            bfs_answer.append(curr)

            for nbr in graph[curr]:
                if visited[nbr] is not True:
                    queue.append(nbr)
                    visited[nbr] = True

        return bfs_answer


if __name__ == '__main__':
    edges = [[0, 1], [0, 2], [1, 2], [1, 3], [1, 4], [2, 5], [3, 4], [3, 5]]
    n = 6
    src = 0

    bfs = BreadthFirstSearch()
    
    bfs_answer = bfs.breadth_first_search(edges, n, src)
    for node in bfs_answer:
        print(node, end = " ")
        