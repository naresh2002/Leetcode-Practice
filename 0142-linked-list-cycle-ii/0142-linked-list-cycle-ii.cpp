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
    // (head) TO (first node where cycle begins) = X distance
    // (first node where cycle begins) TO (where slow ans fast pointer meets) = Y distance
    // (where slow ans fast pointer meets) TO (first node where cycle begins) = Z distance
    // 2 * (X + Y) = X + Y + Z + Y
    // X = Z (Mathametical proof)
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                break;
            }
        }
        if (!fast || !fast -> next) {
            return NULL;
        }
        ListNode* ans = head;
        while (ans != slow) {
            ans = ans -> next;
            slow = slow -> next;
        }
        return ans;
    }
};