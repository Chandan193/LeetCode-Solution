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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));

        int dir = 1;
        int top = 0, left = 0, bottom = m-1, right = n-1;
        ListNode* temp = head;

        while(top<=bottom && left<=right && temp!=nullptr){
            switch(dir){
                case 1:
                    for(int i=left; i<=right && temp!=nullptr; i++){
                        ans[top][i] = temp->val;
                        temp = temp->next;
                    }
                    top++;
                    break;

                case 2:
                    for(int i=top; i<=bottom && temp!=nullptr; i++){
                        ans[i][right] = temp->val;
                        temp = temp->next;
                    }
                    right--;
                    break;
                case 3:
                    for(int i=right; i>=left && temp!=nullptr; i--){
                        ans[bottom][i] = temp->val;
                        temp = temp->next;
                    }
                    bottom--;
                    break;

                case 4:
                    for(int i=bottom; i>=top && temp!=nullptr; i--){
                        ans[i][left] = temp->val;
                        temp = temp->next;
                    }
                    left++;
                    break;
            }

            dir = (dir%4)+1;
        }

        return ans;
    }
};