/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        ListNode* t1 = headA;
        while(t1 != NULL){
            st.insert(t1);
            t1 = t1->next;
        }
        ListNode* t2 = headB;
        while(t2 != NULL){
            if(st.find(t2) != st.end()) return t2;
            t2 = t2->next;
        }
        return t2;
    }
};