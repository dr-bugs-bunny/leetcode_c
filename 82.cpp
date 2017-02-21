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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** tail = &head;
        while(*tail)
        {
            ListNode* next = (*tail) -> next;
            while(next && next -> val == (*tail) -> val)
                next = next -> next;
            if(next == (*tail) -> next) 
                tail = &((*tail) -> next);
            else 
                *tail = next; 
        }
        return head;
    }
};