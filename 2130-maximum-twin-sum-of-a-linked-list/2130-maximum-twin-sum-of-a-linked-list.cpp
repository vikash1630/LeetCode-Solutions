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
    int pairSum(ListNode* head) {
        vector<int> arr;
        ListNode* temp;
        temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        int i = 0;
        int ans = INT_MIN;
        while (i <= (n/2) - 1) {
            ans = max(ans,arr[i] + arr[n - 1 - i]);
            i++;
        }
        return ans;
    }
};