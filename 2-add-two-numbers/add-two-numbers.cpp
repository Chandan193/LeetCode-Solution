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
        ListNode* l = new ListNode(0);  
        ListNode* head = l; 
        int sum=0, rem=0, car=0;
        while(l1 != nullptr || l2 != nullptr){
            int n1 = (l1 != nullptr) ? l1->val : 0;
            int n2 = (l2 != nullptr) ? l2->val : 0;
            sum = n1 + n2 + car;
            rem = sum%10;
            car = sum/10;

            l -> next = new ListNode(rem);
            l = l->next;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }

        if(car > 0){
            l -> next = new ListNode(car);
        }

        return head->next;
    }
};