#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> seen(deadends.begin(), deadends.end());

        unordered_map<char, vector<char>> turnMap = {
            {'0', {'1', '9'}},
            {'1', {'2', '0'}},
            {'2', {'3', '1'}},
            {'3', {'4', '2'}},
            {'4', {'5', '3'}},
            {'5', {'6', '4'}},
            {'6', {'7', '5'}},
            {'7', {'8', '6'}},
            {'8', {'9', '7'}},
            {'9', {'0', '8'}}
        };

        if (seen.count("0000")) {
            return -1;
        }

        queue<string> q;
        q.push("0000");
        seen.insert("0000");

        int turns = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string currState = q.front();
                q.pop();

                if (currState == target) {
                    return turns;
                }

                for (int j = 0; j < currState.size(); ++j) {
                    char currNumber = currState[j];
                    for (char ch : turnMap[currNumber]) {
                        currState[j] = ch;
                        string newState = currState;
                        if (seen.find(newState) == seen.end()) {
                            q.push(newState);
                            seen.insert(newState);
                        }
                        currState[j] = currNumber;
                    }
                }
            }
            turns += 1;
        }
        return -1;
    }
};
