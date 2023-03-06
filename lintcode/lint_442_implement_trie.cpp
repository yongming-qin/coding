#include "../common.h"


/**
 * @brief 
 * 
 */



struct Node {
    bool isWord = false;
    string word;
    vector<Node*> children;
    Node() {
        this->children = vector<Node*>(26, nullptr);
    }
};


class Trie {
public:
    Trie() {
        head = new Node();
    }

    void insert(string &word) {
        Node* iter = head;
        for (int i = 0; i < word.size(); ++i) {
            int c = word[i] - 'a';
            if (iter->children[c] == nullptr) {
                iter->children[c] = new Node();
            }
            iter = iter->children[c];
        }
        iter->isWord = true;
        iter->word = word;
    }

    bool search(string &word) {
        Node* iter = head;
        for (int i = 0; i < word.size(); ++i) {
            int c = word[i] - 'a';
            if (iter->children[c] == nullptr) return false;
            iter = iter->children[c];
        }
        return iter->isWord;
    }

    bool startsWith(string &prefix) {
        Node* iter = head;
        for (int i = 0; i < prefix.size(); ++i) {
            int c = prefix[i] - 'a';
            if (iter->children[c] == nullptr) return false;
            iter = iter->children[c];
        }
        return true;
    }

private:
    Node* head;
}