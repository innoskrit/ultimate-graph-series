import java.util.*;

class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> seen = new HashSet<>();

        Map<Character, List<Character>> turnMap = new HashMap<>() {
            {
                put('0', List.of('1', '9'));
                put('1', List.of('2', '0'));
                put('2', List.of('3', '1'));
                put('3', List.of('4', '2'));
                put('4', List.of('5', '3'));
                put('5', List.of('6', '4'));
                put('6', List.of('7', '5'));
                put('7', List.of('8', '6'));
                put('8', List.of('9', '7'));
                put('9', List.of('0', '8'));
            }
        };

        for(String deadend : deadends) {
            seen.add(deadend);
        }

        if(seen.contains("0000")) {
            return -1;
        }

        Queue<String> queue = new LinkedList<>();
        queue.add("0000");
        seen.add("0000");

        int turns = 0;
        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int i = 0; i < size; i++) {
                String currState = queue.poll();
                if(currState.equals(target)) {
                    return turns;
                }
                
                char[] currStateArr = currState.toCharArray();
                for(int j = 0; j < currStateArr.length; j++) {
                    char currNumber = currStateArr[j];
                    for(char ch : turnMap.get(currNumber)) {
                        currStateArr[j] = ch;
                        String newState = new String(currStateArr);
                        if(!seen.contains(newState)) {
                            queue.add(newState);
                            seen.add(newState);
                        }
                        currStateArr[j] = currNumber;
                    }
                }
            }
            turns += 1;
        }
        return -1;
    }
}