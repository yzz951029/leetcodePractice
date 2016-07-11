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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *node1 = l1;
		ListNode *node2 = l2;
		ListNode *head = new ListNode(0);
		ListNode *current = head ;
		while (node1&&node2)
		{
			if (node1->val>node2->val)
			{
				current->next = node2;
				node2 = node2->next;
			}
			else
			{
				current->next = node1;
				node1 = node1->next;
			}
			current = current->next;
		}
		if (node1)
			current ->next = node1;
		if (node2)
			current ->next = node2;
		return head->next;
	}
};
