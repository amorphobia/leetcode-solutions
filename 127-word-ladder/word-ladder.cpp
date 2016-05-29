#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        // key: string with one of its charactor replaced by '-', e.g. "dog"->"d-g"
        // value: vector of such strings
        unordered_map<string, vector<string>> dict;
        
        for (string s : wordList) {
            for (int i = 0; i < s.length(); ++i) {
                string k = s;
                k[i] = '-';
                dict[k].push_back(s);
            }
        }
        for (int i = 0; i < endWord.length(); ++i) {
            string k = endWord;
            k[i] = '-';
            dict[k].push_back(endWord);
        }
        
        struct node {
            string val;
            int level;
        };
        
        node root {beginWord, 1};
        
        queue<node> q;
        q.push(root);

        unordered_set<string> shownSet;
        shownSet.insert(root.val);
        while (!q.empty()) {
            node cNode = q.front();
            q.pop();
            // shownSet.insert(cNode.val);
            
            for (int i = 0; i < cNode.val.length(); ++i) {
                string k = cNode.val;
                k[i] = '-';
                vector<string> resVec = dict[k];
                for (string s : resVec) {
                    // if shown before continue
                    if (shownSet.find(s) != shownSet.end()) continue;
                    // if reach the end return
                    if (s == endWord) return (cNode.level + 1);
                    q.push({s, cNode.level + 1});
                    shownSet.insert(s);
                }
            }
        }
        
        return 0;
    }
};

int main() {
    unordered_set<string> wordList {"hot","dot","dog","lot","log"};
 
    Solution sln;

    cout << sln.ladderLength("hit", "cog", wordList) << endl;
}