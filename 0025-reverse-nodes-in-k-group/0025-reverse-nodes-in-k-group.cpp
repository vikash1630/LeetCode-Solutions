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
        // Creating a dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Pointer to keep track of the previous group's tail
        ListNode* groupPrev = dummy;

        while (true) {
            // Finding the k-th node from the groupPrev
            ListNode* kth = getKthNode(groupPrev, k);
            if (!kth) break;

            // Store the next group's head
            ListNode* groupNext = kth->next;

            // Break the chain to reverse current k-group cleanly
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            // Reversing k nodes
            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connecting previous group to the reversed group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        // Returning the new head
        return dummy->next;
    }

    // Helper function to find the k-th node from the current node
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};