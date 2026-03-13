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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int times = right - left + 1;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* before = dummy;

        if (times == 1) {
            return head;
        }
        int i = 1;
        for (int i = 1; i < left; i++) {
            before = curr;
            curr = curr->next;
        } // i = left

        while (times--) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        // curr = 5, prev = 4, before = 1

        before->next->next = curr;
        before->next = prev;
        return dummy->next;
    }
};