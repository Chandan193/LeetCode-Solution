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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        int n = 0;
        for (ListNode* p = head; p; p = p->next) n++;
        
        int size = n / k, extra = n % k;
        ListNode* cur = head;
        for (int i = 0; i < k && cur; i++) {
            ans[i] = cur;
            int part_size = size + (i < extra ? 1 : 0);
            for (int j = 1; j < part_size; j++) cur = cur->next;
            ListNode* next = cur->next;
            cur->next = nullptr;
            cur = next;
        }
        return ans;
    }
};