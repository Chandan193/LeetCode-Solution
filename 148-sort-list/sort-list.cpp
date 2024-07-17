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
    ListNode* sortList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(head==nullptr) return head;

        vector<int> v;
        
        while(head != nullptr){
            int num = head->val;
            v.push_back(num);
            head = head -> next;
        }

        sort(v.begin(), v.end());

        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;

        for(int i=0; i<v.size(); i++){
            temp-> next = new ListNode(v[i]);
            temp = temp -> next;
        }

        return newHead->next;
    }
};