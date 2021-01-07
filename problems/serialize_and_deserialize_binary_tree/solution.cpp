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

    // Encodes a tree to a single string.
    string str;
    int inf = 1e5;
    string conv(int num) {
        string tmp = "N";
        if (num == inf) return tmp;
        return to_string(num);
    }
    void trav(TreeNode* root) {
        if (root == NULL) return ;   
        int l, r;
        l = r = inf;
        if (root->left) l = root->left->val;
        if (root->right) r = root->right->val;
        string a = conv(l) + ",";
        string b = conv(r) + ",";
        str += a;
        str += b;
        trav(root->left);
        trav(root->right);
    }
    
    string serialize(TreeNode* root) {
        if (root == NULL) str += "N,";
        else {
            str += to_string(root->val) + ",";
        }
        trav(root);
        str.pop_back();
        return str;
    }
    int i = 0;
    int next(string data) {
        string num;
        while (i < data.size() && data[i] != ',') {
            num += data[i];
            i++;
        }
        i++;
        if (num == "N") return inf;
        int v = stoi(num);
        return v;
    }
    
    void trav1(TreeNode* root, string data) {
        if (root == NULL) return ;
        int l = next(data);
        int r = next(data);
        if (l != inf) root->left = new TreeNode(l);
        if (r != inf) root->right = new TreeNode(r);
        trav1(root->left, data);
        trav1(root->right, data);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        int num = next(data);
        if (num == inf) return root;
        root = new TreeNode(num);
        trav1(root, data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));