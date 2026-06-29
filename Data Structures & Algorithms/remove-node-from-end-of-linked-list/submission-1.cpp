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

// fast pointer -> will move for n time
// slow pointer -> will move until the fast pointer reach the end of list

//    -1 [1, 2, 3, 4], n=2
//           x     x
//     

#define DEBUG 1

#if DEBUG
    #define DBG(x) do { cout << x << endl; } while(0)
#else
    #define DBG(x) do {} while(0)
#endif

class Solution {
public:
    void display(ListNode* head) {
        ListNode* curr = head;
        string txt = "";
        while (curr) {
            txt += to_string(curr->val) + " ";
            curr = curr->next;
        }

        if (!txt.empty()) {
            DBG(txt);
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode();
        temp->next = head;

        ListNode* slow = temp;
        ListNode* fast = temp;

        while(n--) {
            fast = fast->next;
        }

        while (fast && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        display(temp->next);
        return temp->next;
    }
};
