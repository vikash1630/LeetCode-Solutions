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
        int len = 1;
        if (head == NULL) return NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
        temp = head;
        
        // To delete len - n th node
        int i = 1;
        if (len - n == 1) return temp->next;
        while (temp != NULL) {
            if (i == len - n - 1) break;
            temp = temp->next;
            i++;
        }
        ListNode* del = temp->next;
        if (del == NULL) return head;
        temp->next = del->next;
        return head;
    }
};