from collections import deque, defaultdict
from typing import List

class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        stop_to_bus_map = defaultdict(list)
        stop_visited = set()
        bus_visited = set()

        for bus, stops in enumerate(routes):
            for stop in stops:
                stop_to_bus_map[stop].append(bus)

        if source == target:
            return 0
        if source not in stop_to_bus_map:
            return -1

        queue = deque([source])
        stop_visited.add(source)

        buses_taken = 0
        while queue:
            size = len(queue)
            for _ in range(size):
                curr_stop = queue.popleft()
                if curr_stop == target:
                    return buses_taken
                bus_list = stop_to_bus_map[curr_stop]
                for bus in bus_list:
                    if bus not in bus_visited:
                        for stop in routes[bus]:
                            if stop not in stop_visited:
                                queue.append(stop)
                                stop_visited.add(stop)
                        bus_visited.add(bus)
            buses_taken += 1

        return -1
