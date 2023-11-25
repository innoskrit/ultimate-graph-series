#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> stopToBusMap;
        unordered_set<int> stopVisited;
        unordered_set<int> busVisited;

        for (int bus = 0; bus < routes.size(); ++bus) {
            for (int stop : routes[bus]) {
                stopToBusMap[stop].push_back(bus);
            }
        }

        if (source == target) {
            return 0;
        }

        if (stopToBusMap.find(source) == stopToBusMap.end()) {
            return -1;
        }

        queue<int> q;
        q.push(source);
        stopVisited.insert(source);

        int busesTaken = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int currStop = q.front();
                q.pop();

                if (currStop == target) {
                    return busesTaken;
                }

                vector<int>& busList = stopToBusMap[currStop];
                for (int bus : busList) {
                    if (busVisited.find(bus) == busVisited.end()) {
                        for (int stop : routes[bus]) {
                            if (stopVisited.find(stop) == stopVisited.end()) {
                                q.push(stop);
                                stopVisited.insert(stop);
                            }
                        }
                        busVisited.insert(bus);
                    }
                }
            }
            busesTaken += 1;
        }

        return -1;
    }
};
