/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	void serialize(TreeNode* root, ostringstream& out )
    {
    	queue<TreeNode*> q;
    	q.push(root);

    	while(!q.empty())
    	{
    		TreeNode* tmp = q.front();
    		q.pop();
    		if(tmp)
    		{
    			out << tmp->val << "#";
    			q.push(tmp -> left);
    			q.push(tmp -> right);
    		}
    		else
    			out << "#";
    	}
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
    	vector<TreeNode*> v;
    	TreeNode* tmp;

        for(int i = 0, j = 0; j <= i && i < data.length(); i++, j++)
        {
        	while(data[i] != '#') i++;
        	if(j < i)
        	{
        		int value = 0, sign = 1;
        		if(data[j] == '-')
        		{
        		    sign = -1;
        		    j++;
        		}
        		while(j < i) value += (int)(data[j] - '0') * pow(10, i-(j++)-1);
        		tmp = new TreeNode(value * sign);
        		v.push_back(tmp);
        	}
        	else
        		v.push_back(nullptr);
        }

        for(int i = 0, j = 0; i < v.size() && j < v.size(); i++)
        {
        	if(!v[i]) continue;
        	else
        	{
        		v[i] -> left = v[++j];
        		v[i] -> right = v[++j];
        	}
        }

        return v[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));