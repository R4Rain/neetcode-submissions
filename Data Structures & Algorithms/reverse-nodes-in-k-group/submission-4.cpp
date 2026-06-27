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

 // 0 0 0 0 0 0 0
 // x    y y


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        int cnt = 1;
        ListNode* curr = head;
        ListNode* prev = dummy;
        while (curr) {
            if (cnt % k == 0) {
                ListNode* nextGroup = curr->next;
                ListNode* startGroup = prev->next;

                ListNode* previous = nextGroup;
                ListNode* current = startGroup;
    
                while (current != nextGroup) {
                    ListNode* next = current->next;
                    current->next = previous;
                    previous = current;
                    current = next;
                }
                prev->next = previous;
                prev = startGroup;
                curr = nextGroup;
            } else {
                curr = curr->next;
            }
            cnt++;
        }
        return dummy->next;
    }
};
