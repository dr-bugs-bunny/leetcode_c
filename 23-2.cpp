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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i = lists.size() - 1; i >= 0; i--)
        {
            if(lists[i] == NULL) 
                lists.erase(lists.begin() + i);
        }
        
        int listNum = lists.size();
        if(listNum == 0) return NULL;

        ListNode* head = NULL;
        int min = lists[0]->val, min_index = 0;

        for(int i = 1; i < listNum; i++)
        {
            if(min > lists[i]->val)
            {
                min = lists[i]->val;
                min_index = i;
            }
        }

        head = lists[min_index];
        lists[min_index] = lists[min_index]->next;
        head->next = mergeKLists(lists);
        
        return head;
    }
};