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
    ListNode* mergeNodes(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        int x = 0;

        while (head != nullptr) {
            x += head->val;
            head = head->next;
            if (head != nullptr && head->val == 0) {
                temp->next = new ListNode(x);
                x = 0;
                temp = temp->next;
            }
        }

        return newHead->next;
    }
};