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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        vector<int> v;
        while(curr != nullptr){
            v.push_back(curr->val);
            curr = curr->next;
        }

        reverse(v.begin()+left-1, v.begin()+right);

        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;

        for(int i=0; i<v.size(); i++){
            temp -> next = new ListNode(v[i]);
            temp = temp -> next;
        }

        return newHead -> next;
    }
};