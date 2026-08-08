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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;
        while (true) {

            ListNode* groupEnd = groupPrev;

            for (int i = 0; i < k; i++) {
                groupEnd = groupEnd->next;
                if (!groupEnd) {
                    return dummy.next;
                }
            }

            ListNode* groupNext = groupEnd->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            
            ListNode* oldstart = groupPrev->next;
            groupPrev->next = groupEnd;
            groupPrev = oldstart;
        }
    }
};