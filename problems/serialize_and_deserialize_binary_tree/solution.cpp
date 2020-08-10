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
    string serialize(TreeNode* root) {
        if (root == NULL) return "X";
        else {
            string str;
            queue<TreeNode*> Q;
            str += to_string(root->val) + ",";
            Q.push(root);
            TreeNode* t = NULL;
            while (!Q.empty()) {
                t = Q.front();
                Q.pop();
                if (t->left == NULL) {
                    str += "X,";
                }
                else {
                    str += to_string(t->left->val) + ",";
                    Q.push(t->left);
                }
                if (t->right == NULL) {
                    str += "X,";
                }
                else {
                    str += to_string(t->right->val) + ",";
                    Q.push(t->right);
                }
            }
            str.pop_back();
            return str;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> token;
        stringstream check(data);
        string str;
        while (getline(check, str, ',')) token.push_back(str);
        int len = token.size();
        queue<TreeNode*> Q;
        TreeNode* pp = NULL;
        TreeNode* root = new TreeNode();
        if (len == 0) return NULL;
        auto get = [&](string str) {
            if (str[0] == 'X') return -99999999;
            else return stoi(str);
        };
        Q.push(root);
        if (token[0] == "X") return NULL;
        root->val = get(token[0]);
        int idx = 0;
        while (!Q.empty()) {
            pp = Q.front();
            Q.pop();
            int l = idx + 1;
            int r = idx + 2;
            if (l < len) {
                int val = get(token[l]);
                if (val != -99999999) {
                    pp->left = new TreeNode(val);
                    Q.push(pp->left);
                }
            }
            if (r < len) {
                int val = get(token[r]);
                if (val != -99999999) {
                    pp->right = new TreeNode(val);
                    Q.push(pp->right);
                }
            }
            idx += 2;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));