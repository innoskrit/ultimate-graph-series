import java.util.*;

class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        Map<Integer, List<Integer>> stopToBusMap = new HashMap<>();
        Set<Integer> stopVisited = new HashSet<>();
        Set<Integer> busVisited = new HashSet<>();

        for(int bus = 0; bus < routes.length; bus++) {
            for(int stop : routes[bus]) {
                if(!stopToBusMap.containsKey(stop)) {
                    stopToBusMap.put(stop, new ArrayList<>());
                }
                stopToBusMap.get(stop).add(bus);
            }
        }

        if(source == target) return 0;
        if(!stopToBusMap.containsKey(source)) return -1;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(source);
        stopVisited.add(source);

        int busesTaken = 0;
        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int i = 0; i < size; i++) {
                int currStop = queue.poll();
                if(currStop == target) return busesTaken;
                List<Integer> busList = stopToBusMap.get(currStop);
                for(int bus : busList) {
                    if(!busVisited.contains(bus)) {
                        for(int stop : routes[bus]) {
                            if(!stopVisited.contains(stop)) {
                                queue.add(stop);
                                stopVisited.add(stop);
                            }
                        }
                        busVisited.add(bus);
                    }
                }
            }
            busesTaken += 1;
        }
        return -1;
    }
}