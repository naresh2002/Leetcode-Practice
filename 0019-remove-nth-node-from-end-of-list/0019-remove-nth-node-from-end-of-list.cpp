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
    void solve (ListNode *head, int &curr, int n) {
        if (!head) {
            return;
        }
        solve (head -> next, curr, n);
        if (curr == n) {
            if (head -> next -> next) {
                head -> next = head -> next -> next;
            }
            else {
                head -> next = NULL;
            }
        }
        curr++;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = new ListNode(-1);
        temp -> next = head;
        int curr = 0;
        solve(temp, curr, n);
        return temp -> next;
    }
};