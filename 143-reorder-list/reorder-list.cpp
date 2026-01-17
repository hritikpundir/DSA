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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is the mid node
        ListNode* head2 = slow->next;
        slow->next = NULL;

        // reverse 2nd half of linked list
        head2 = reverseList(head2);

        // merge two halfs alternatively
        while (head2 != NULL) {
            ListNode* t1 = head->next;
            ListNode* t2 = head2->next;
            head->next = head2;
            head2->next = t1;
            head = t1;
            head2 = t2;
        }
    }
};