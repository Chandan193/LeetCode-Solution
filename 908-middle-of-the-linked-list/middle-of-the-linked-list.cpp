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
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            n++;
            temp = temp -> next;
        }

        int cnt = 0;

        while(head != nullptr){
            cnt++;
            if(cnt == (n/2)+1) break;
            head = head -> next;
        }
        return head;
    }
};