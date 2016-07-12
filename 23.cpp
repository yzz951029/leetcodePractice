#include<iostream>
#include<vector>
using namespace std;

//用了类似归并排序的做法，AC了真爽。。。

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return merge(lists);
	}
	ListNode* merge(vector<ListNode *> &lists){
		int size = lists.size();
		if (size == 0)
			return nullptr;
		if (size == 1)
			return lists[0];
		int mid = (size + 1) / 2;
		vector<ListNode *> leftSub(lists.begin(), lists.begin() + mid);
		vector<ListNode *> rightSub(lists.begin() + mid, lists.end());
		ListNode *left = merge(leftSub);
		ListNode *right = merge(rightSub);
		return mergeTwoLists(left, right);
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *node1 = l1;
		ListNode *node2 = l2;
		ListNode *head = new ListNode(0);
		ListNode *current = head;
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
			current->next = node1;
		if (node2)
			current->next = node2;
		return head->next;
	}
};

int main()
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(0);
	vector<ListNode *>x;
	x.push_back(a);
	x.push_back(b);
	vector<ListNode *> temp(x.begin()+1, x.end());
	Solution s;
	ListNode * answer = s.mergeKLists(x);
	while (answer)
	{
		cout << answer->val << " ";
		answer = answer->next;
	}
	system("Pause");

}