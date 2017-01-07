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
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        
        vector<ListNode*> v, v1;
        while(head != NULL)
        {
            v.push_back(head);
            head = head->next;
        }
        v1 = v;

        int len = 1;
        while(len < v.size())
        {
            int double_len = len << 1;
            for(int head1 = 0, v1_index = 0; head1 + len < v.size(); head1 += len)
            {
                int start = head1;
                int head2 = start + len;
                int end = (head1 + double_len > v.size()? v.size(): head1 + double_len);
                while(true)
                {
                    if(head1 < start + len && head2 < end)
                    {
                        if(v[head1]->val < v[head2]->val)
                            v1[v1_index++] = v[head1++];
                        else
                            v1[v1_index++] = v[head2++];
                    }
                    else if(head1 < start + len)
                    {
                        v1[v1_index++] = v[head1++];
                    }
                    else if(head2 < end)
                    {
                        v1[v1_index++] = v[head2++];
                    }
                    else
                        break;
                }
            }

            v = v1;
            len = double_len;
        }

        if(v.size() > 1)
            for(int i = v.size() - 2; i >= 0; i--)
            {
                v[i]->next = v[i+1];
            }
        v[v.size()-1]->next = NULL;

        head = v[0];
        return head;
    }
};