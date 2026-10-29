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
    int ListLength(ListNode* head) {
        int cnt = 1;
        ListNode* tem = head;
        while (tem->next != NULL) {
            tem = tem->next;
            cnt++;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL || head == NULL) {
            return {};
        }
        int len = ListLength(head);
        ListNode* temp = head;

        if (n == len) {
            ListNode* Newhead = head->next;
            delete (head);
            return Newhead;
        }

        int i = 1;
        while (i < (len - n)) {
            temp = temp->next;
            i++;
        }
        ListNode* temp2 = temp->next;
        temp->next = temp2->next;
        delete (temp2);
        return head;
    }
};