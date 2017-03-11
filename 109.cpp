/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	TreeNode* sortedListToBST(ListNode* head, ListNode* tail, int n)
	{
        if(head == tail || !n) return nullptr;

		int m = n / 2;
		ListNode* mid = head;
		while(m--) mid = mid -> next;
		TreeNode* root = new TreeNode(mid -> val);
		root -> left = sortedListToBST(head, mid, n / 2);
		root -> right = sortedListToBST(mid -> next, tail, (n - 1) / 2);
		return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
    	ListNode * tail = head;
    	int n = 0;
    	while(tail)
    	{
    		tail = tail -> next;
    		n++;
    	}
        return sortedListToBST(head, tail, n);
    }
};