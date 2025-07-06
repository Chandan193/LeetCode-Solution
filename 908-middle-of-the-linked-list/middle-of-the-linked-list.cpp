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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL){
            temp = temp->next;
            n++;
        }
        int i = 0;
        ListNode* curr = head;
        while(curr != NULL){
            i++;
            if(i==(n/2)+1) break;
            curr = curr->next;
        }
        return curr;
    }
};