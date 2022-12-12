#include <bits/stdc++.h>
#include "input.h"

using namespace std;

// TODO: check edge cases
class Trie {
    public:
        bool isLeaf;
        vector<Trie*> children;

        Trie() {
            vector<Trie*> children(10, NULL);
            this->isLeaf = false;
            this->children = children
        }

        bool insert(string s) {
            if (this->isLeaf) return false;
            if (s.size() == 1) {
                Trie* leaf = new Trie();
                leaf->isLeaf = true;
                this->children[s[0]-'a'] = leaf;
                return true;
            }
            if (this->children[s[0]-'a'] == NULL) {
                Trie* node = new Trie();
                this->children[s[0]-'a'] = node;
            }
            return this->children[s[0]-'a']->insert(s.substr(1));
        }
};

void noPrefix(vector<string> words) {
    Trie* trie = new Trie();
    for (int i = 0; i < words.size(); i++) {
        if (!trie->insert(words[i])) {
            cout "BAD SET" << endl << words[i] << endl;
            return;
        }
    }
    cout << "GOOD SET" << endl;
}

int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    return 0;
}