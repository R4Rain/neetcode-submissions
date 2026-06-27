/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummy = new Node(-1);
        Node *curr_dummy = dummy;
        Node *curr = head;
        unordered_map<Node*, Node*> node_map;

        while (curr != NULL) {
            Node *new_node;
            if (node_map.count(curr) != 0) {
                new_node = node_map[curr];
                cout << "existing node: " << new_node->val << endl;
            } else {
                new_node = new Node(curr->val);
                node_map[curr] = new_node;
                cout << "created node: " << new_node->val << endl;
            }
            curr_dummy->next = new_node;
            
            if (curr->random) {
                Node *random_node;
                if (node_map.count(curr->random) != 0) {
                    random_node = node_map[curr->random];
                    cout << "existing node random: " << random_node->val << endl;
                } else {
                    random_node = new Node(curr->random->val);
                    cout << "created node random: " << random_node->val << endl;
                    node_map[curr->random] = random_node;
                }
                new_node->random = random_node;
            }
            curr_dummy = new_node;
            curr = curr->next;
        }
        return dummy->next;
    }
};
