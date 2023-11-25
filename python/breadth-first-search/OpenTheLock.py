from typing import List
from collections import deque

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        seen = set(deadends)

        turn_map = {
            '0': ['1', '9'],
            '1': ['2', '0'],
            '2': ['3', '1'],
            '3': ['4', '2'],
            '4': ['5', '3'],
            '5': ['6', '4'],
            '6': ['7', '5'],
            '7': ['8', '6'],
            '8': ['9', '7'],
            '9': ['0', '8']
        }

        if "0000" in seen:
            return -1

        queue = deque(["0000"])
        seen.add("0000")

        turns = 0
        while queue:
            size = len(queue)
            for _ in range(size):
                curr_state = queue.popleft()

                if curr_state == target:
                    return turns

                for j in range(len(curr_state)):
                    curr_number = curr_state[j]
                    for ch in turn_map[curr_number]:
                        new_state = curr_state[:j] + ch + curr_state[j+1:]
                        if new_state not in seen:
                            queue.append(new_state)
                            seen.add(new_state)

            turns += 1
            
        return -1
