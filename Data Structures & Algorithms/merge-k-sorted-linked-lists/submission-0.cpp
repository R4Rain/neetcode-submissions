/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Compare {
    public:
        bool operator() (ListNode* &a, ListNode* &b) {
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> min_heap;

        for (int i = 0;i < lists.size();i++) {
            if (lists[i]) {
                min_heap.push(lists[i]);
            }
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        while (!min_heap.empty()) {
            ListNode *top = min_heap.top();
            curr->next = top;
            curr = curr->next;
            min_heap.pop();

            if (top->next != NULL) {
                min_heap.push(top->next);
            }
        }
        curr->next = NULL;
        return dummy->next;
    }
};