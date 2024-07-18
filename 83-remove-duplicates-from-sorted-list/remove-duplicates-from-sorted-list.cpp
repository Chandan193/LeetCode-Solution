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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;

       ListNode* curr = head;

       map<int, int> mp;
       while(curr != nullptr){
        mp[curr->val]++;
        curr = curr -> next;
       }  
       ListNode* newHead = new ListNode(0);
       ListNode* temp = newHead;

       for(auto &it : mp){
        temp -> next = new ListNode(it.first);
        temp = temp -> next;
       }
       return newHead->next;
    }
};