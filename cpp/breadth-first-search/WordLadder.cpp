#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        
        int wordCount = 1;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                string currWord = q.front();
                q.pop();
                
                if (currWord == endWord) {
                    return wordCount;
                }
                
                for (int j = 0; j < currWord.size(); ++j) {
                    char originalChar = currWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        currWord[j] = c;
                        if (wordSet.find(currWord) != wordSet.end()) {
                            q.push(currWord);
                            wordSet.erase(currWord);
                        }
                    }
                    currWord[j] = originalChar;
                }
            }
            wordCount += 1;
        }
        
        return 0;
    }
};
