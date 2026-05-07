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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 1;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int len = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }
        int pos = len - n;
        if (pos < 0) return head;
        if (pos == 0) return head->next;
        temp = head;
        while (temp->next != NULL) {
            if (cnt == pos) {
                ListNode* newTemp = temp->next;
                temp->next = temp->next->next;
                newTemp->next = NULL;
                return head;
            }
            temp = temp->next;
            cnt++;
        }
        return head;
    }
};