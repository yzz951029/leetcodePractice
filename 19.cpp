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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *current = head;
		int size = 0;
		while (current)
		{
			size++;
			current = current->next;
		}
		int num = size - n - 1;
		if (num == -1)
			return head->next;
		current = head;
		for (int i = 0; i < num; i++)
		{
			current = current->next;
		}
		ListNode *m = current->next;
		current->next = m->next;
		delete m;
		return head;
	}
};