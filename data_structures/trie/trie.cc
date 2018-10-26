
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class TrieNode {
    unordered_map<char, TrieNode*> children;
    char data;
    bool isLeaf;

    public:
        TrieNode() : data(0), isLeaf(true) {}

        TrieNode(char c) : data(c), isLeaf(true) {}

        void addChar(char charToAdd) {
            if(children.find(charToAdd) != children.end()) {
                TrieNode* tn = new TrieNode(charToAdd);
                children[charToAdd] = tn;
            }
        }

        TrieNode* getChild(char c) {
            if(children.find(c) == children.end()) {
                addChar(c);
            }
            return children[c];
        }

        bool hasChar(char c) {
            return children.find(c) != children.end();
        }

};


class Trie {
    TrieNode* root;
    
    public:
        Trie() : root(new TrieNode()) {}

        Trie(string w) : root(new TrieNode()) {
            this->addWord(w);
        }
 
        Trie(vector<string> wordList) : root(new TrieNode()) {
            for(string w : wordList) {
                this->addWord(w);
            }
        }       

        void addWord(string word) {
            TrieNode* cur = root;
            for(int i = 0; i < word.size(); ++i) {
                cur = cur->getChild(word[i]);
            } 
        }

        bool contains(string word) {
            TrieNode* cur = root;
            for(int i = 0; i < word.size(); ++i) {
                if(!cur->hasChar(word[i])) {
                    return false;
                }
            }
            return true;
        }


};
