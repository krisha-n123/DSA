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
         vector<int> ans = {-1, -1};

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int pos = 1;
        int first = -1;
        int last = -1;

        int minDist = INT_MAX;
        int maxDist = 0;

        while (next != nullptr) {

            // Check whether curr is a critical point
            bool isMax = (curr->val > prev->val && curr->val > next->val);
            bool isMin = (curr->val < prev->val && curr->val < next->val);

            if (isMax || isMin) {

                if (first == -1) {
                    // First critical point
                    first = pos;
                } 
                else {
                    minDist = min(minDist, pos - last);
                    maxDist = pos - first;
                }

                last = pos;
            }

            prev = curr;
            curr = next;
            next = next->next;
            pos++;
        }

        if (first == last)
            return ans;

        return {minDist, maxDist};
    }
};