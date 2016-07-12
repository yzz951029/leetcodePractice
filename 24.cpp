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
    ListNode* swapPairs(ListNode* head) {
        ListNode *current = head;
        if(!current)
            return nullptr;
        if(head->next)
            head = head->next;
        else
            return head;
        ListNode *s =nullptr;
        while(current)
        {
            if(!current->next)
                break;
            ListNode *ne = current->next;
            if(s)
                s->next = ne;
            current->next = ne->next;
            ne->next = current;
            s = current;
            current = current->next;
        }
        return head;
    }
};