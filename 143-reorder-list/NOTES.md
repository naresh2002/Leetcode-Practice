# REVERSE LINKED LIST :
​
ListNode* reverse(ListNode *head) {
if (head == NULL || head->next == NULL) return head;
ListNode* new_head = reverse(head->next);
head->next->next = head;
head->next = NULL;
return new_head;
}