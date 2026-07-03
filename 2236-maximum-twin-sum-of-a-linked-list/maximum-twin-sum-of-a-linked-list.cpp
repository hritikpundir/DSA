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
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) { // even length
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is mid

        ListNode* head2 = reverseList(slow);

        ListNode* t1 = head;
        ListNode* t2 = head2;

        int sum = 0;
        int maxSum = 0;
        while (t1 != NULL && t2 != NULL) {
            sum = t1->val + t2->val;
            maxSum = max(maxSum, sum);
            t1 = t1->next;
            t2 = t2->next;
        }
        return maxSum;
    }
};