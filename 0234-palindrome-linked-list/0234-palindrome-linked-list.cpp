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
    ListNode *temp;
    
    bool dfs(ListNode *head) {
        if (!head) {
            return true;
        }
        bool ans = dfs(head -> next);
        ans &= (temp -> val == head -> val);
        temp = temp -> next;
        return ans;
    }
    
    bool isPalindrome(ListNode* head) {
        temp = head;
        return dfs(head);
    }
};