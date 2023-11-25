from typing import List
from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        word_set = set(wordList)
        
        queue = deque([beginWord])
        word_count = 1
        while queue:
            queue_size = len(queue)
            for i in range(queue_size):
                curr_word = queue.popleft()
                if curr_word == endWord:
                    return word_count
                
                word_list = list(curr_word)
                for j in range(len(word_list)):
                    original_char = word_list[j]
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        word_list[j] = c
                        next_word = ''.join(word_list)
                        if next_word in word_set:
                            queue.append(next_word)
                            word_set.remove(next_word)
                    word_list[j] = original_char
            
            word_count += 1
        
        return 0
