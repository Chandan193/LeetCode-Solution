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
    ListNode* rotateRight(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(head == nullptr) return head;
        ListNode* curr = head;
        vector<int> v;
        while(curr != nullptr){
            v.push_back(curr->val);
            curr = curr->next;
        }

        k = k%v.size();
        reverse(v.begin(), v.end());
        reverse(v.begin(), v.begin()+k);
        reverse(v.begin()+k, v.end());

        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;

        for(int i=0; i<v.size(); i++){
            temp -> next = new ListNode(v[i]);
            temp = temp -> next;
        }

        return newHead->next;
    }
};