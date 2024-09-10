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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==nullptr) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;

        vector<int> arr,arr2;

        while(prev->next!=nullptr && curr!=nullptr){
            int ele = gcd(prev->val, curr->val);
            arr.push_back(ele);
            prev = prev->next;
            curr = curr->next;
        }

        ListNode* test = head;
        while(test!=nullptr){
            arr2.push_back(test->val);
            test = test->next;
        }

        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;

        int i = 0, j=0;
        while(i<arr.size() && j<arr2.size()){
            int x1 = arr2[i];
            temp->next = new ListNode(x1);
            temp=temp->next;
            i++;

            int x2 = arr[j];
            temp->next = new ListNode(x2);
            temp=temp->next;
            j++;
        }
         
        temp->next = new ListNode(arr2[arr2.size()-1]);
        

        return newHead->next;
    }
};