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
    unordered_map<Node*, Node*> used_node;
public:
    Node* clone(Node* node) {
        if (node == NULL) return node;

        if (used_node.count(node)) return used_node[node];

        Node* new_node = new Node(node->val);
        used_node.emplace(node, new_node);

        for (auto &neighbor: node->neighbors) {
            new_node->neighbors.push_back(clone(neighbor));
        }
        return new_node;
    }


    Node* cloneGraph(Node* node) {
        return clone(node);
    }
};
