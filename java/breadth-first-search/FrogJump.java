import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public boolean canCross(int[] stones) {
        int destination = stones[stones.length - 1];
        
        Map<Integer, Set<Integer>> hashMap = new HashMap<>();
        for(int stone : stones) {
            hashMap.put(stone, new HashSet<>());
        }
        
        hashMap.get(stones[0]).add(1);
        
        for(int i = 0; i < stones.length; i++) {
            int currStonePosition = stones[i];
            for(int jump : hashMap.get(currStonePosition)) {
                int nextPosition = currStonePosition + jump;
                if(nextPosition == destination) {
                    return true;
                }
                if(hashMap.containsKey(nextPosition)) {
                    if(jump - 1 > 0) {
                        hashMap.get(nextPosition).add(jump - 1);
                    }
                    hashMap.get(nextPosition).add(jump);
                    hashMap.get(nextPosition).add(jump + 1);
                }   
            }
        }

        return false;
    }
}