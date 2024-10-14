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
    ListNode* front;
    bool solve (ListNode* node) {
        if (!node) {
            return true;
        }
        bool ans = solve(node -> next);
        if (front -> val != node -> val) {
            return false;
        }
        front = front -> next;
        return ans;
    }
    
    bool isPalindrome(ListNode* head) {
        front = head;
        return solve(head);
    }
};