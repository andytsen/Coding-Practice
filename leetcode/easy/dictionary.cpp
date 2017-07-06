#include <vector>

using namespace std;

class TrieNode {
    public:
        char symbol;
        TrieNode* next;
        TrieNode(char c, TrieNode* node) : symbol(c), next(node) {}
};

class Trie {
    private:
        vector<TrieNode*> dict;
    public:
        Trie() : dict(vector<TrieNode*>(26, nullptr)) {
            for(int i = 0; i < 26; i++) {
                dict[i] = new TrieNode('a' + 1, nullptr);
            }
        }
};


