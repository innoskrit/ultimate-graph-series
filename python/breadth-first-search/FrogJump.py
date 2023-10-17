from typing import List

class Solution:
    def canCross(self, stones: List[int]) -> bool:

        destination = stones[-1]

        hash_map = dict()
        for stone in stones:
            hash_map[stone] = set()
        
        hash_map[stones[0]].add(1)

        for i in range(len(stones)):
            curr_stone_position = stones[i]
            for jump in hash_map[curr_stone_position]:
                next_position = curr_stone_position + jump
                if next_position == destination:
                    return True
                if next_position in hash_map:
                    if jump - 1 > 0:
                        hash_map[next_position].add(jump - 1)
                    hash_map[next_position].add(jump)
                    hash_map[next_position].add(jump + 1)

        return False

        