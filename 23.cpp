/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	ListNode* merge2Lists(ListNode* list1, ListNode* list2)
	{
		if(list1 == NULL) return list2;
		if(list2 == NULL) return list1;

		ListNode* head = (list1->val <= list2->val)? list1: list2;
		head->next = (list1->val <= list2->val)? merge2Lists(list1->next, list2): merge2Lists(list1, list2->next);

		return head;
	}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listNum = lists.size();
        if(listNum == 0) return NULL;

        while(listNum > 1)
        {
        	for(int i = 0; i < listNum/2; i++)
        		lists[i] = merge2Lists(lists[i], lists[listNum-1-i]);
        	listNum = (listNum + 1) / 2;
        }

        return lists[0];
    }
};