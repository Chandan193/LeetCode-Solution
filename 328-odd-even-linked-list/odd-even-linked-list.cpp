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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> arr;
        ListNode* curr = head;
        while(curr!=nullptr){
            arr.push_back(curr->val);
            curr = curr->next;
        }
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        for(int i=0; i<arr.size(); i++){
            if(i%2==0){
                temp->next = new ListNode(arr[i]);
                temp = temp->next;
            }
        }
        for(int i=0; i<arr.size(); i++){
            if(i%2==1){
                temp->next = new ListNode(arr[i]);
                temp = temp->next;
            }
        }
        return newHead->next;
    }
};