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

 // 0 1 2 3 4 5 6 7 8 9 9
 //           s         s

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = dummy;
        while (n--) {
            curr = curr->next;
        }

        while (curr != NULL && curr->next != NULL) {
            curr = curr->next;
            prev = prev->next;
        }

        prev->next = prev->next->next;
        return dummy->next;
    }
};
