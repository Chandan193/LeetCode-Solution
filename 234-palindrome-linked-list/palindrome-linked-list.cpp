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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int i=0, j=arr.size()-1;
        while(i<j){
            if(arr[i]!=arr[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};