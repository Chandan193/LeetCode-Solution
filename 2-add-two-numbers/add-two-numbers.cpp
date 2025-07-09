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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        int c = 0, r = 0;
        while(l1 != NULL || l2 != NULL){
            int a =(l1 != NULL) ? l1->val : 0;
            int b =(l2 != NULL) ? l2->val : 0;
            r = (a+b+c)%10;
            c = (a+b+c)/10;

            temp->next = new ListNode(r);
            temp = temp->next;            
           
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }

        if(c>0) temp->next = new ListNode(c);

        return newHead->next;
    }
};