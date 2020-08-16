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

        void preorder(TreeNode * root, string & s) 
    {
        if (!root)
            return;

        if (s != "")
            s += ',';
        s += to_string(root -> val);

        preorder(root -> left, s);
        preorder(root -> right, s);
    }

    string serialize(TreeNode * root) {

        string s = "";
        preorder(root, s);
        return s;
    }
    // Decodes your encoded data to tree.
    int x;
    unordered_map < int, int > m;

    TreeNode * solve(int i, int j, vector < int > & p) 
    {
        if (i > j)
            return NULL;

        int val = p[x++];
        TreeNode * r = new TreeNode(val);

        int ind = m[val];
        r -> left = solve(i, ind - 1, p);
        r -> right = solve(ind + 1, j, p);

        return r;
    }

    TreeNode * deserialize(string data) {
        if (data == "")
            return NULL;

        vector < int > pre;

        for (int i = 0; i < data.length(); i++) {
            string s = "";
            while (i < data.length() && data[i] != ',') {
                s += data[i];
                i++;
            }

            pre.push_back(stoi(s));
        }

        vector < int > in (pre.begin(), pre.end());
        sort( in .begin(), in .end()); 
        int n = pre.size();

        for (int i = 0; i < n; i++)
            m[ in [i]] = i;

        x = 0;
        return solve(0, n - 1, pre);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));