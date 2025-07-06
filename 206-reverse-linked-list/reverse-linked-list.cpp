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
    ListNode* reverseList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        ListNode* newHead = new ListNode(0);
        ListNode* curr = newHead;
        for(int i=arr.size()-1; i>=0; i--){
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        return newHead->next;
    }
};