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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* c1 = list1;
        ListNode* c2 = list2;
        
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;

        while(c1!=nullptr && c2!=nullptr){
            int v1 = c1->val;
            int v2 = c2->val;
            if(v1<v2){
                temp->next = new ListNode(v1);
                temp = temp->next;
                c1 = c1->next;
            }
            else if(v2<v1){
                temp -> next = new ListNode(v2);
                temp = temp->next;
                c2 = c2->next;
            }
            else{
                temp->next = new ListNode(v1);
                temp = temp->next;
                temp -> next = new ListNode(v2);
                temp = temp->next;
                c1 = c1->next;
                c2 = c2->next;
            }
            
        }

        while(c1 != nullptr){
            temp->next = new ListNode(c1->val);
            temp = temp->next;
            c1 = c1->next;
        }

        while(c2 != nullptr){
            temp->next = new ListNode(c2->val);
            temp = temp->next;
            c2 = c2->next;
        }

        return newHead->next;
    }
};