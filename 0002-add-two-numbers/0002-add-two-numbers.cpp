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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int a = l1->val + l2->val + carry;
            if (a > 9) {
                carry = 1;
                a = a % 10;
            }
            else carry = 0;
            temp->val = a;
            if (l2->next != NULL || l1->next != NULL) 
            {
            ListNode* dum = new ListNode();
            temp->next = dum;
            temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            int a = l1->val + carry;
            if (a > 9) {
                carry = 1;
                a = a % 10;
            }
            else carry = 0;
            temp->val = a;
            if (l1->next != NULL) 
            {
            ListNode* dum = new ListNode();
            temp->next = dum;
            temp = temp->next;
            }
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int a = l2->val + carry;
            if (a > 9) {
                carry = 1;
                a = a % 10;
            }
            else carry = 0;
            temp->val = a;
            if (l2->next != NULL) 
            {
            ListNode* dum = new ListNode();
            temp->next = dum;
            temp = temp->next;
            }
            l2 = l2->next;
        }
        if (carry) {
            ListNode* dum = new ListNode(carry);
            temp->next = dum;
            temp = temp->next;
        }
        return ans;
    }
};