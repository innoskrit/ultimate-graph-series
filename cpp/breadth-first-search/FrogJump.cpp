#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int destination = stones.back();

        map<int, set<int>> hashMap;
        for (int stone : stones) {
            hashMap[stone] = set<int>();
        }

        hashMap[stones[0]].insert(1);

        for (int i = 0; i < stones.size(); i++) {
            int currStonePosition = stones[i];
            for (int jump : hashMap[currStonePosition]) {
                int nextPosition = currStonePosition + jump;
                if (nextPosition == destination) {
                    return true;
                }
                if (hashMap.find(nextPosition) != hashMap.end()) {
                    if (jump - 1 > 0) {
                        hashMap[nextPosition].insert(jump - 1);
                    }
                    hashMap[nextPosition].insert(jump);
                    hashMap[nextPosition].insert(jump + 1);
                }
            }
        }

        return false;
    }
};
