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
        vector<int> arr1, arr2, arr3;
        ListNode* c1 = l1;
        ListNode* c2 = l2;

        while(c1!=nullptr){
            arr1.push_back(c1->val);
            c1 = c1->next;
        }

        while(c2!=nullptr){
            arr2.push_back(c2->val);
            c2 = c2->next;
        }

        int car = 0, i = arr1.size()-1, j = arr2.size()-1;

        while(i>=0 && j>=0){
            int sum = (arr1[i]+arr2[j]+car)%10;
            car = (arr1[i]+arr2[j]+car)/10;
            arr3.push_back(sum);
            i--;
            j--;
        }

        while(i>=0){
            int sum = (arr1[i]+car)%10;
            car = (arr1[i]+car)/10;
            arr3.push_back(sum);
            i--;
        }

        while(j>=0){
            int sum = (arr2[j]+car)%10;
            car = (arr2[j]+car)/10;
            arr3.push_back(sum);
            j--;
        }

        if(car>0) arr3.push_back(car);

        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;

        for(int i=arr3.size()-1; i>=0; i--){
            temp->next = new ListNode(arr3[i]);
            temp = temp->next;
        }

        return newHead->next;
    }
};