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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *father = head, *son = NULL;

        if(head != NULL)
        {
        	while(father != NULL && (son = father-> next) != NULL)
        	{
        		ListNode* tmp = head;
        		if(son->val < head->val)
        		{
        			father->next = son->next;
        			son->next = head;
        			head = son;
        			continue;
        		}
    			while(tmp != father && tmp->next->val < son->val) 
    				tmp = tmp->next;
        		if(tmp != father)
        		{
        			father->next = son->next;
        			son->next = tmp->next;
        			tmp->next = son;
        		}
        		else father = father->next;
        	}
        }
        
        return head;
    }
};