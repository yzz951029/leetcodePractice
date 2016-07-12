class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *head = new ListNode(0);
		ListNode *current = head;
		int size = lists.size();
		bool empty = true;
		do
		{
			empty = true;
			int min = INT_MAX;
			int index = 0;
			//ListNode *minNode = nullptr;
			for (int i = 0; i<size; i++)
			{
				if (lists[i])
				{
					empty = false;
					if (lists[i]->val<min)
					{
						//minNode = list[i];
						min = lists[i]->val;
						index = i;
					}
				}
			}
			if (!empty)
			{
				current->next = lists[index];
				current = current->next;
				lists[index] = lists[index]->next;
			}
		} while (!empty);
		return head->next;
	}
};