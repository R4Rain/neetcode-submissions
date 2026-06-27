#include<bits/stdc++.h>

class PrefixTree {
public:
    class Node {
        public:
            bool isEnd;
            Node* children[26];

            Node() : isEnd(false) {
                memset(children, NULL, sizeof(children));
            }
    };

    Node* root;

    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;

        for (int i = 0;i < word.size();i++) {
            int idx = word[i] - 'a';
            // If children exists
            if (curr->children[idx]) {
                curr = curr->children[idx];
            } else {
                Node* new_node = new Node();
                curr->children[idx] = new_node;
                curr = new_node;
            }
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (int i = 0;i < word.size();i++) {
            int idx = word[i] - 'a';
            // If children exists
            if (curr->children[idx]) {
                curr = curr->children[idx];
            } else {
                return false;
            }
        }

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (int i = 0;i < prefix.size();i++) {
            int idx = prefix[i] - 'a';
            if (curr->children[idx]) {
                curr = curr->children[idx];
            } else {
                return false;
            }
        }
        return true;
    }
};
