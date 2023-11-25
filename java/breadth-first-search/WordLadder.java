import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> set = new HashSet<>(wordList);

        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);

        int wordCount = 1;
        while(!queue.isEmpty()) {
            int queueSize = queue.size();
            for(int i = 0; i < queueSize; i++) {
                String currWord = queue.poll();
                if(currWord.equals(endWord)) return wordCount;
                char word[] = currWord.toCharArray();
                for(int j = 0; j < word.length; j++) {
                    char ch = word[j];
                    for(char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        String nextWord = new String(word);
                        if(set.contains(nextWord)) {
                            queue.add(nextWord);
                            set.remove(nextWord);
                        }
                    }
                    word[j] = ch;
                }
            }
            wordCount += 1;
        }
        return 0;
    }
}