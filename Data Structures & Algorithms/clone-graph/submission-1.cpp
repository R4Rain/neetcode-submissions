/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#define DEBUG 0

#if DEBUG
    #define DBG(x) do { cout << x << endl; } while(0)
#else
    #define DBG(x) do {} while(0)
#endif

class Solution {
private:
    unordered_map<int, Node*> used_node;
public:
    Node* clone(Node* node) {
        if (node == NULL) return node;

        Node* current = new Node(node->val);
        vector<Node*> new_neighbors;
        used_node.emplace(node->val, current);

        for (auto &neighbor: node->neighbors) {
            if (neighbor == NULL) continue;

            if (used_node.count(neighbor->val)) {
                new_neighbors.push_back(used_node[neighbor->val]);
            } else {
                new_neighbors.push_back(clone(neighbor));
            }
        }
        current->neighbors = new_neighbors;
        return current;
    }


    Node* cloneGraph(Node* node) {
        return clone(node);
    }
};
