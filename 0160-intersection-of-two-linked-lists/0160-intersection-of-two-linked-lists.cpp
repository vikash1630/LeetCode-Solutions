/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1= headA;
        ListNode* temp2 = headB;
        bool flag1 = true;
        bool flag2 = true;
        while (temp1 != temp2) {
            if (temp1 == NULL) {
                if (flag1) {
                    temp1 = headB;
                    flag1 = false;
                }
                else {
                    temp1 = headA;
                    flag1 = true;
                }
                temp2 = temp2->next;
            }
            else if (temp2 == NULL) {
                if (flag2) {
                    temp2 = headA;
                    flag2 = false;
                }
                else {
                    temp2 = headB;
                    flag2 = true;
                }
                temp1 = temp1->next;
            }
            else {
                temp1 = temp1->next;
                temp2 = temp2->next;
            } 
        }
        return temp1;
    }
};