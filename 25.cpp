#include<iostream>
using namespace std;

struct ListNode {
    int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head)
			return nullptr;
		ListNode * before = nullptr;
		ListNode *current = head;
		ListNode *newHead = new ListNode(0);
		newHead->next = head;
		before = newHead;
		int cnt = 0;
		while (current)
		{
			cnt++;
			if (cnt == k)
			{
				ListNode *tmpCur = current;
				ListNode *tmp = current->next;
				before->next = reverseList(head, current->next);
				before = head;
				head->next = tmp;
				head = tmp;
				current = tmp;
				cnt = 0;
				continue;
			}
			current = current->next;
		}
		return newHead->next;
	}

	ListNode *reverseList(ListNode *head, ListNode *ne)
	{
		ListNode *current = head;
		ListNode *newHead = new ListNode(0);
		newHead->next = head;
		ListNode *before = nullptr;
		while (current != ne)
		{
			ListNode *tmp = current->next;
			current->next = before;
			newHead->next = current;
			before = current;
			current = tmp;
		}
		return newHead->next;
	}
};


int main()
{
	ListNode *head = new ListNode(1);
	ListNode *ne = new ListNode(2);
	ListNode *ne2 = new ListNode(3);
	ListNode *ne3 = new ListNode(4);
	head->next = ne;
	ne->next = ne2;
	ne2->next = ne3;
	Solution s;
	ListNode * a = s.reverseKGroup(head, 2);
	while (a)
	{
		cout << a->val;
		a = a->next;
	}
	system("Pause");
}