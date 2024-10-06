class Solution {
public:
    // https://leetcode.com/problems/word-ladder/discuss/5864616/Easy-To-Understand-BFS-Solution
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet (wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [currWord, steps] = q.front();
            q.pop();
            
            for (int i = 0; i < currWord.size(); i++) {
                char originalChar = currWord[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == originalChar) {
                        continue;
                    }
                    currWord[i] = ch;
                    
                    if (currWord == endWord) {
                        return steps + 1;
                    }
                    
                    if (wordSet.find(currWord) != wordSet.end()) {
                        q.push({currWord, steps + 1});
                        wordSet.erase(currWord);
                    }
                }
                currWord[i] = originalChar;
            }
        }
        return 0;
    }
};