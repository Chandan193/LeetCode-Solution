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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> cp;
        ListNode *p = nullptr, *c = head, *n = head ? head->next : nullptr;
        int pos = 0;

        while (n != nullptr) {
            if (p != nullptr) {
                if ((c->val > p->val && c->val > n->val) ||
                    (c->val < p->val && c->val < n->val)) {
                    cp.push_back(pos);
                }
            }
            p = c;
            c = n;
            n = n->next;
            pos++;
        }

        if (cp.size() < 2) {
            return {-1, -1};
        }

        int minDist = INT_MAX;
        int maxDist = cp.back() - cp.front();

        for(int i = 1; i < cp.size(); i++) {
            minDist = min(minDist, cp[i] - cp[i - 1]);
        }

        return {minDist, maxDist};
    }
};