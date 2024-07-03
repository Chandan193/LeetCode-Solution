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
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> hashmap;
        ListNode* temp = head;
        while(temp != NULL){
            if(hashmap.find(temp) != hashmap.end()){
                return true;
            }
            hashmap[temp] = 1;
            temp = temp -> next;
        }
        return false;
    }
};